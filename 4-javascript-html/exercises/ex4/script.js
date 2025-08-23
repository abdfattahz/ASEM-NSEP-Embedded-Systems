//script.js

// Ask name just like before
// let Name = prompt("Please enter your name");
// alert("Hello your name is " + Name);
// document.getElementById("myName").innerHTML = "<h1>Hello " + Name + " 👒</h1>";

// Ask for a year
let year = parseInt(prompt("Please enter a year:"), 10);

// Function to test leap year
function isLeapYear(y) {
  if (y % 400 === 0) return true;
  if (y % 100 === 0) return false;
  return y % 4 === 0;
}

if (isNaN(year)) {
  alert("That was not a valid number! ❌");
} else {
  if (isLeapYear(year)) {
    alert(year + " is a leap year! 🎉");
  } else {
    // find nearest before
    let before = year - 1;
    while (!isLeapYear(before)) before--;

    // find nearest after
    let after = year + 1;
    while (!isLeapYear(after)) after++;

    alert(
      year +
        " is NOT a leap year 🚫\n" +
        "Previous leap year: " +
        before +
        "\n" +
        "Next leap year: " +
        after
    );
  }
}
