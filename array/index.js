function login() {
  const email = document.getElementById("email").value;
  const password = document.getElementById("password").value;

  fetch("http://localhost:3000/login", {
    method: "POST",
    headers: {
      "Content-Type": "application/json"
    },
    body: JSON.stringify({ email, password })
  })
  .then(res => res.json())
  .then(data => {
    document.getElementById("result").innerText = data.message;
  })
  .catch(err => console.log(err));
}
