let Name = prompt("Please enter your name");

let words = Name.trim().split(/\s+/);
let formattedWords = [];

for (let i = 0; i < words.length; i++) {
  let word = words[i];
  let capitalized = word.charAt(0).toUpperCase() + word.slice(1).toLowerCase();
  formattedWords.push(capitalized);
}

let formattedName = formattedWords.join(" ");

document.getElementById("myName").innerHTML =
  "<h1>Hello your name is " + formattedName + " 😹</h1>";
