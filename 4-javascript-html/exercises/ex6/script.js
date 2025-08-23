//script.js

let numStudent;

while (true) {
  numStudent = parseInt(prompt("Please enter a number between 1 to 20"));

  if (numStudent >= 1 && numStudent <= 20) break;
  alert("That was not a valid number! ❌");
}

let cgpas = [];

for (let i = 0; i < numStudent; i++) {
  let cgpa;
  while (true) {
    cgpa = Number.parseFloat(
      prompt(`Please enter student ${i + 1} CGPA (between 0.00 and 4.00):`)
    );
    if (!Number.isNaN(cgpa) && cgpa >= 0.0 && cgpa <= 4.0) break;
    alert(`CGPA for student ${i + 1} is invalid`);
  }
  cgpas.push(cgpa);
}

// (optional) compute stats and display
const min = Math.min(...cgpas);
const max = Math.max(...cgpas);
const avg = cgpas.reduce((a, b) => a + b, 0) / cgpas.length;

document.getElementById("results").innerHTML = `
  <h2>CGPA Results</h2>
  <p>Minimum CGPA: ${min.toFixed(2)}</p>
  <p>Maximum CGPA: ${max.toFixed(2)}</p>
  <p>Average CGPA: ${avg.toFixed(2)}</p>
`;
