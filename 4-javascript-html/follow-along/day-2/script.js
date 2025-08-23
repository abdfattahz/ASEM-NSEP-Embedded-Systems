let num1 = prompt("Please enter your first number");
let num2 = prompt("Please enter your second number");

num1 = Number(num1);
num2 = Number(num2);

let sum = num1 + num2;
let dif = num1 - num2;
let mul = num1 * num2;

let sElement = "<p> Summation is " + sum + "</p>";
sElement += "<p> Difference is " + dif + "</p>";
sElement += "<p> Multiplication is " + mul + "</p>";

document.getElementById("myName").innerHTML = sElement;
