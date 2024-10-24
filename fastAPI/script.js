document.getElementById("login-form").addEventListener("submit", async function (event) {
    event.preventDefault();

    const username = document.getElementById("login-username").value;
    const password = document.getElementById("login-password").value;

    try {
        const response = await fetch("/login", {
            method: "POST",
            headers: {
                "Content-Type": "application/json"
            },
            body: JSON.stringify({ username: username, password: password })
        });

        if (!response.ok) {
            throw new Error("로그인 실패");
        }

        const data = await response.json();
        localStorage.setItem("token", data.access_token);

        document.getElementById("login-section").style.display = "none";
        document.getElementById("post-section").style.display = "block";
        loadPosts();

    } catch (error) {
        document.getElementById("message").innerText = "로그인 실패: " + error.message;
    }
});

// 게시물 불러오기
async function loadPosts() {
    const token = localStorage.getItem("token");

    try {
        const response = await fetch("/posts", {
            headers: {
                "Authorization": `Bearer ${token}`
            }
        });

        const posts = await response.json();
        const postList = document.getElementById("post-list");
        postList.innerHTML = ""; // 기존 게시물 초기화

        posts.forEach(post => {
            const li = document.createElement("li");
            li.textContent = post.title;
            postList.appendChild(li);
        });

    } catch (error) {
        document.getElementById("message").innerText = "게시물 불러오기 실패";
    }
}

// 회원가입 처리
document.getElementById("signup-form").addEventListener("submit", async function (event) {
    event.preventDefault();

    const username = document.getElementById("signup-username").value;
    const email = document.getElementById("signup-email").value;
    const password = document.getElementById("signup-password").value;

    try {
        const response = await fetch("/signup", {
            method: "POST",
            headers: {
                "Content-Type": "application/json"
            },
            body: JSON.stringify({
                username: username,
                email: email,
                password: password
            })
        });

        if (!response.ok) {
            throw new Error("회원가입 실패");
        }

        document.getElementById("message").innerText = "회원가입 성공! 로그인하세요.";
    } catch (error) {
        document.getElementById("message").innerText = "회원가입 실패: " + error.message;
    }
});