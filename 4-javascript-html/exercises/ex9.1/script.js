const students = [];

document.getElementById("studentForm").addEventListener("submit", function (e) {
  e.preventDefault(); // prevent form reload

  // 1) get values
  let studentName = document.getElementById("name").value.trim();
  let studentAge = parseInt(document.getElementById("age").value, 10);
  let cgpa = parseFloat(document.getElementById("cgpa").value);

  // 2) capitalize each word in name
  let formattedName = studentName
    .split(/\s+/)
    .map((w) => w.charAt(0).toUpperCase() + w.slice(1).toLowerCase())
    .join(" ");

  // 3) push into array
  students.push({ studentName: formattedName, studentAge, cgpa });

  // 4) clear form inputs
  document.getElementById("studentForm").reset();

  // 5) update display
  updateResults();
});

function updateResults() {
  // compute stats
  let min = students[0].cgpa;
  let max = students[0].cgpa;
  let sum = 0;
  for (let i = 0; i < students.length; i++) {
    let c = students[i].cgpa;
    if (c < min) min = c;
    if (c > max) max = c;
    sum += c;
  }
  let avg = sum / students.length;

  // build table rows
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

  // render
  document.getElementById("results").innerHTML = `
    <h2>CGPA Results</h2>
    <table>
      <thead>
        <tr><th>Name</th><th>Age</th><th>CGPA</th></tr>
      </thead>
      <tbody>
        ${rowsHTML}
      </tbody>
    </table>
    <div id="stats">
      <p>Minimum CGPA: ${min.toFixed(2)}</p>
      <p>Maximum CGPA: ${max.toFixed(2)}</p>
      <p>Average CGPA: ${avg.toFixed(2)}</p>
    </div>
  `;
}
