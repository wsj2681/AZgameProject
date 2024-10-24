import schemas
from fastapi import FastAPI, Depends, HTTPException, status
from sqlalchemy.orm import Session
from passlib.context import CryptContext
from jose import JWTError, jwt
from datetime import timedelta
from database import get_db
import models
import utils
from fastapi.middleware.cors import CORSMiddleware



app = FastAPI()

app.add_middleware(
    CORSMiddleware,
    allow_origins=["*"],  # 모든 출처 허용
    allow_credentials=True,
    allow_methods=["*"],  # 모든 메서드 허용
    allow_headers=["*"],  # 모든 헤더 허용
)

pwd_context = CryptContext(schemes=["bcrypt"], deprecated="auto")

# 회원가입
@app.post("/signup", response_model=schemas.User)
def signup(user: schemas.UserCreate, db: Session = Depends(get_db)):
    hashed_password = pwd_context.hash(user.password)
    db_user = models.User(username=user.username, email=user.email, password=hashed_password)
    db.add(db_user)
    db.commit()
    db.refresh(db_user)
    return db_user

# 로그인
@app.post("/login", response_model=schemas.Token)
def login(user: schemas.UserLogin, db: Session = Depends(get_db)):
    db_user = db.query(models.User).filter(models.User.username == user.username).first()
    if not db_user or not pwd_context.verify(user.password, db_user.password):
        raise HTTPException(status_code=status.HTTP_401_UNAUTHORIZED, detail="Invalid credentials")
    
    access_token = utils.create_access_token(data={"sub": db_user.username})
    return {"access_token": access_token, "token_type": "bearer"}

# 게시물 등록
@app.post("/posts/", response_model=schemas.Post)
def create_post(post: schemas.PostCreate, db: Session = Depends(get_db)):
    db_post = models.Post(
        title=post.title,
        content=post.content,
        board_id=post.board_id,
        user_id=post.user_id
    )
    db.add(db_post)
    db.commit()
    db.refresh(db_post)
    return db_post

@app.get("/posts", response_model=List[schemas.Post])
def get_posts(db: Session = Depends(get_db)):
    return db.query(models.Post).all()

# 좋아요 누르기
@app.post("/posts/{post_id}/like", response_model=schemas.Like)
def like_post(post_id: int, user_id: int, db: Session = Depends(get_db)):
    db_like = models.Like(post_id=post_id, user_id=user_id)
    db.add(db_like)
    db.commit()
    db.refresh(db_like)
    return db_like

# 댓글 달기
@app.post("/posts/{post_id}/comments", response_model=schemas.Comment)
def comment_on_post(post_id: int, comment: schemas.CommentCreate, db: Session = Depends(get_db)):
    db_comment = models.Comment(
        post_id=post_id,
        user_id=comment.user_id,
        content=comment.content
    )
    db.add(db_comment)
    db.commit()
    db.refresh(db_comment)
    return db_comment