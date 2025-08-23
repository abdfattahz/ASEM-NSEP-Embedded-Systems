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

function enterStudent(i) {
  // name
  let rawName = prompt(`Please enter student ${i + 1} name:`) || "";
  const studentName = capitalizeName(rawName);

  // age
  let studentAge;
  while (true) {
    const v = prompt(`Please enter student ${i + 1} age:`);
    if (v === null) continue;
    studentAge = parseInt(v, 10);
    if (!Number.isNaN(studentAge) && studentAge > 0) break;
    alert("Invalid age");
  }

  // cgpa
  let cgpa;
  while (true) {
    const v = prompt(`Please enter student ${i + 1} CGPA (0.00–4.00):`);
    if (v === null) continue;
    cgpa = parseFloat(v);
    if (!Number.isNaN(cgpa) && cgpa >= 0 && cgpa <= 4) break;
    alert("Invalid CGPA");
  }

  students.push({ studentName, studentAge, cgpa });

  // compute stats so far
  let min = students[0].cgpa;
  let max = students[0].cgpa;
  let sum = 0;
  for (const s of students) {
    if (s.cgpa < min) min = s.cgpa;
    if (s.cgpa > max) max = s.cgpa;
    sum += s.cgpa;
  }
  const avg = sum / students.length;

  // log now (DevTools can render before the next prompt)
  console.clear();
  console.table(students);
  console.log(`Min CGPA: ${min.toFixed(2)}`);
  console.log(`Max CGPA: ${max.toFixed(2)}`);
  console.log(`Avg CGPA: ${avg.toFixed(2)}`);
  console.log("------");

  // schedule next student so UI can update
  if (i + 1 < numStudent) {
    setTimeout(() => enterStudent(i + 1), 0);
  }
}

// start
console.log("script loaded");
enterStudent(0);
