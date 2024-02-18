const title = document.getElementById("chng_title");
const btn = document.getElementById("btn");
const btn_2 = document.getElementById("bg_ctl");
const btn_rv = document.getElementById("btn_rv");
const remove_heading = document.querySelector("h3");
const add_btn = document.getElementById("add_btn");
const target = document.getElementById("target");

btn.addEventListener("mouseover", () => {
  title.textContent = "WelCome SIAM PATHAN";
});

function rndomColor() {
  let color = [
    "red",
    "coral",
    "saddlebrown",
    "cadetblue",
    "#0f93ec",
    "lightblue",
    "lightgreen",
  ];
  return color[Math.floor(Math.random() * color.length)];
}

btn_2.addEventListener("click", () => {
  document.body.style.backgroundColor = rndomColor();
});

btn_rv.addEventListener("mouseover", () => {
  remove_heading.remove();
});

add_btn.addEventListener("click", () => {
  const newSpan = document.createElement("span");
  newSpan.textContent = "This is ADD by JS";

  if (target.hasChildNodes()) target.appendChild(newSpan);
  else target.innerHTML = newSpan.outerHTML;
});
