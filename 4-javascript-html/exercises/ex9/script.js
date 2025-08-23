let numStudent;

while (true) {
  const v = prompt("Please enter a number between 1 to 20");
  if (v === null) continue;
  numStudent = parseInt(v, 10);
  if (!Number.isNaN(numStudent) && numStudent >= 1 && numStudent <= 20) break;
  alert("That was not a valid number! ❌");
}

const students = [];

function capitalizeName(raw) {
  return raw
    .trim()
    .split(/\s+/)
    .map((w) => (w[0] || "").toUpperCase() + (w.slice(1) || "").toLowerCase())
    .join(" ");
}

for (let i = 0; i < numStudent; i++) {
  // name
  let rawName = prompt(`Please enter student ${i + 1} name:`) || "";
  const studentName = capitalizeName(rawName);

  // age
  let studentAge;
  while (true) {
    const v = prompt(`Please enter student ${i + 1} age:`);
    studentAge = parseInt(v, 10);
    if (!Number.isNaN(studentAge) && studentAge > 0) break;
    alert("Invalid age");
  }

  // cgpa
  let cgpa;
  while (true) {
    const v = prompt(`Please enter student ${i + 1} CGPA (0.00–4.00):`);
    cgpa = parseFloat(v);
    if (!Number.isNaN(cgpa) && cgpa >= 0 && cgpa <= 4) break;
    alert("Invalid CGPA");
  }

  students.push({ studentName, studentAge, cgpa });

  // compute stats so far
  let min = students[0].cgpa;
  let max = students[0].cgpa;
  let sum = 0;

  // let rowsHTML = "";
  // for (let m = 0; m < students.length; m++) {
  //   const y = students[m];
  //   rowsHTML += `
  //     <tr>
  //       <td>${y.studentName}</td>
  //       <td>${y.studentAge}</td>
  //       <td>${y.cgpa.toFixed(2)}</td>
  //     </tr>`;
  // }

  for (let s of students) {
    if (s.cgpa < min) min = s.cgpa;
    if (s.cgpa > max) max = s.cgpa;
    sum += s.cgpa;
  }
  let avg = sum / students.length;

  // print to console
  console.table(students);
  console.log("Current Students:", students);
  console.log(`Min CGPA: ${min.toFixed(2)}`);
  console.log(`Max CGPA: ${max.toFixed(2)}`);
  console.log(`Avg CGPA: ${avg.toFixed(2)}`);
  console.log("------");
}

// compute stats on numbers only
let max = students[0].cgpa;
let min = students[0].cgpa;
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
