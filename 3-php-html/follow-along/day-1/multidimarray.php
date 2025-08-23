<?php

$students = [
    ['name' => 'Alice', 'age' => 20, 'grade' => 'A'],
    ['name' => 'Bob', 'age' => 22, 'grade' => 'B'],
    ['name' => 'Charlie', 'age' => 21, 'grade' => 'C']
];

?>

<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Multidimensional Array Example</title>
</head>

<body>
    <h1>Student Mark </h1>
    <table border="100">
        <tr>
            <th>Name</th>
            <th>Age</th>
            <th>Grade</th>
        </tr>
        <?php foreach ($students as $student): ?>
            <tr>
                <td><?= htmlspecialchars($student['name']) ?></td>
                <td><?= htmlspecialchars($student['age']) ?></td>
                <td><?= htmlspecialchars($student['grade']) ?></td>
            </tr>
        <?php endforeach; ?>
</body>

</html>