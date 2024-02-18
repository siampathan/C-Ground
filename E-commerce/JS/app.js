const form = document.getElementById("myForm");
const mobileInput = document.getElementById("mobile");
const maleCheckbox = document.getElementById("male");
const femaleCheckbox = document.getElementById("female");

form.addEventListener("submit", (event) => {
  event.preventDefault();

  const mobileValue = mobileInput.value.trim();
  if (mobileValue.length !== 11) {
    alert("Mobile number must be 11 digits.");
    mobileInput.focus();
    return;
  }

  const emailValue = document.getElementById("email").value.trim();
  const emailRegex = /^\w+([\.-]?\w+)*@\w+([\.-]?\w+)*(\.\w{2,3})+$/;
  if (!emailRegex.test(emailValue)) {
    alert("Please enter a valid email address.");
    document.getElementById("email").focus();
    return;
  }

  if (!(maleCheckbox.checked ^ femaleCheckbox.checked)) {
    alert('Please select either "Male" or "Female", but not both.');
    return; // Prevent further form submission
  }

  alert("Form submitted successfully!");
});
