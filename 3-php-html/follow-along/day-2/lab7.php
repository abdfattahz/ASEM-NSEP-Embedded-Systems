<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Lab 7</title>
</head>
<body>
   <form action="lab7.php" method="post"> 
    <label for="temperature">Temperature: </label>
    <div class="field-with-button">
        <input type="number" id="temperature" name="temperature" step="0.1" required />
        <input type="submit" value="Submit" />
</body>
</html>


<?php
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $temperature = $_POST["temperature"];

    // validate : numeric check
    if(!is_numeric($temperature)) {
        echo "<p>Invalid input!</p>";
        exit;
    }

    // Sanitize for display
    $temperature = htmlspecialchars($temperature);

     // Add timestamp to log
    date_default_timezone_set("Asia/Kuala_Lumpur");
    $timestamp = date("Y-m-d H:i:s");
    $entry = $timestamp . " | Temperature: " . $temperature . "°C\n";

    echo "<h2>Received Data:</h2>";
    echo "Temperature: " . $temperature . "°C" . "<br>";

    file_put_contents("log.txt" , $entry , FILE_APPEND);
    echo "<p>Data saved to log.txt</p>";

    // Log the temperature to a separate file
}

// file_exists("log.txt") ? $data = file_get_contents("log.txt") : $data = "No data found!";
// echo "<h2>Data Log:</h2>";
// echo nl2br($data);

// Show last 5 log entries
if (file_exists("log.txt")) {
    $lines = file("log.txt", FILE_IGNORE_NEW_LINES | FILE_SKIP_EMPTY_LINES);
    $lastFive = array_slice($lines, -5);
    
    echo "<h2>Data Log:</h2>";
    foreach ($lastFive as $line) {
        echo htmlspecialchars($line) . "<br>";
    }
} else {
    echo "<h2>Data Log:</h2>No data found!";
}

?>