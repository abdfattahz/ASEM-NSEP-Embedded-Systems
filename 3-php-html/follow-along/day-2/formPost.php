<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Form Post Example</title>
<style>
    /* Two-column form: labels right-aligned, fields left-aligned */
    form {
      display: grid;
      grid-template-columns: 120px 1fr; /* label width, field column */
      gap: 10px 12px;                   /* row gap, column gap */
      max-width: 520px;
    }
    label { justify-self: end; align-self: center; }
    input[type="text"], input[type="number"] { width: 260px; }

    /* Put temperature input and submit on the same line */
    .field-with-button {
      display: flex;
      align-items: center;
      gap: 8px;
    }

    /* (optional) center the whole form on the page */
    body { margin: 10px; }
    /* To center page-wide: 
    body { min-height: 100vh; display:flex; justify-content:center; align-items:flex-start; }
    */
  </style>
</head>
<body>
  <form action="formPost.php" method="post">
    <label for="device">Device:</label>
    <input type="text" id="device" name="device" required />

    <label for="temperature">Temperature:</label>
    <div class="field-with-button">
      <input type="number" id="temperature" name="temperature" step="0.1" required />
      <input type="submit" value="Submit" />
    </div>
  </form>

</body>
</html>

<?php

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $device = $_POST["device"];
    $temperature = $_POST["temperature"];

    echo "<h2>Received Data:</h2>";
    echo "Device: " . htmlspecialchars($device) . "<br>";
    echo "Temperature: " . htmlspecialchars($temperature) . "°C" . "<br>";

    print_r($_POST);

    file_put_contents("data.txt", "Device: " . $device . "\nTemperature: " . $temperature . "°C\n", FILE_APPEND);
    echo "<p>Data saved to data.txt</p>";
}

file_exists("data.txt") ? $data = file_get_contents("data.txt") : $data = "No data found.";
echo "<h2>Data from file:</h2>";
echo nl2br($data); 

?>