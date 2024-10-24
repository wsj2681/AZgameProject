from pydantic import BaseModel, EmailStr
from typing import Optional
from datetime import datetime

# Token schema
class Token(BaseModel):
    access_token: str
    token_type: str

class UserBase(BaseModel):
    username: str
    email: EmailStr

class UserCreate(UserBase):
    password: str

class UserLogin(BaseModel):
    username: str
    password: str

class User(UserBase):
    user_id: int
    last_login_ip: Optional[str]
    created_at: datetime
    updated_at: Optional[datetime]

    class Config:
        from_attributes = True

class PostBase(BaseModel):
    title: str
    content: str

class PostCreate(PostBase):
    board_id: int
    user_id: int

class Post(PostBase):
    post_id: int
    board_id: int
    user_id: int
    view_count: int
    created_at: datetime
    updated_at: datetime

    class Config:
        from_attributes = True

class CommentBase(BaseModel):
    content: str

class CommentCreate(CommentBase):
    post_id: int
    user_id: int

class Comment(CommentBase):
    comment_id: int
    post_id: int
    user_id: int
    created_at: datetime
    updated_at: datetime

    class Config:
        from_attributes = True

class LikeCreate(BaseModel):
    post_id: int
    user_id: int

class Like(BaseModel):
    like_id: int
    post_id: int
    user_id: int
    created_at: datetime

    class Config:
        from_attributes = True