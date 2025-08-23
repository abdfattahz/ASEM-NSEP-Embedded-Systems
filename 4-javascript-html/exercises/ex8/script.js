//script.js

let numStudent;

while (true) {
  numStudent = parseInt(prompt("Please enter a number between 1 to 20"));

  if (numStudent >= 1 && numStudent <= 20) break;
  alert("That was not a valid number! ❌");
}

let students = [];
for (let i = 0; i < numStudent; i++) {
  // 1) ask for student name
  let studentName = prompt(`Please enter student ${i + 1} name:`);
  // 2) format the name
  let words = studentName.trim().split(/\s+/);
  let formattedWords = [];
  for (let n = 0; n < words.length; n++) {
    let word = words[n];
    let capitalized =
      word.charAt(0).toUpperCase() + word.slice(1).toLowerCase();
    formattedWords.push(capitalized);
  }

  let formattedName = formattedWords.join(" ");

  // 3) ask for student age
  let studentAge;
  while (true) {
    studentAge = Number.parseInt(prompt(`Please enter student ${i + 1} age:`));
    if (!Number.isNaN(studentAge) && studentAge > 0) break;
    alert(`Age for student ${i + 1} is invalid`);
  }

  // 4) ask for student CGPA
  let cgpa;
  while (true) {
    cgpa = Number.parseFloat(
      prompt(`Please enter student ${i + 1} CGPA (between 0.00 and 4.00):`)
    );
    if (!Number.isNaN(cgpa) && cgpa >= 0.0 && cgpa <= 4.0) break;
    alert(`CGPA for student ${i + 1} is invalid`);
  }
  students.push({ studentName: formattedName, studentAge, cgpa });
}

// compute stats on numbers only
let min = students[0].cgpa;
let max = students[0].cgpa;
let sum = 0;

for (let k = 0; k < students.length; k++) {
  const s = students[k];
  if (s.cgpa < min) min = s.cgpa;
  if (s.cgpa > max) max = s.cgpa;
  sum += s.cgpa;
}

const avg = sum / students.length;

// build table rows with a loop
let rowsHTML = "";
for (let i = 0; i < students.length; i++) {
  const s = students[i];
  rowsHTML += `
    <tr>
      <td>${s.studentName}</td>
      <td>${s.studentAge}</td>
      <td>${s.cgpa.toFixed(2)}</td>
    </tr>`;
}

// render table + stats
document.getElementById("results").innerHTML = `
  <h2>CGPA Results</h2>
  <table border="1" cellpadding="6" cellspacing="0">
    <thead>
      <tr><th>Name</th><th>Age</th><th>CGPA</th></tr>
    </thead>
    <tbody>
      ${rowsHTML}
    </tbody>
  </table>
  <p>Minimum CGPA: ${min.toFixed(2)}</p>
  <p>Maximum CGPA: ${max.toFixed(2)}</p>
  <p>Average CGPA: ${avg.toFixed(2)}</p>
`;
