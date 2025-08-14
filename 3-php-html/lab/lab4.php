<?php
declare(strict_types=1);
$sensorReadings = [30, 23.0, 21.8, 24.2, 20.9];
$avg = calculateAverage($sensorReadings);
$firstReading = $sensorReadings[0];

function celsiusToFahrenheit(float $celsius): float {
    return ($celsius * 9/5) + 32;
}

function fahrenheitToCelsius(float $fahrenheit): float {
    return ($fahrenheit - 32) * 5/9;
}

function isAboveThreshold(float $temperature, float $threshold = 22.0): bool {
    return $temperature > $threshold;
}

function calculateAverage(array $readings): float {
    return array_sum($readings) / count($readings);
}

function celsiusToKelvin(float $celsius): float {
    return $celsius + 273.15;
}

?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
  <h1>Lab 4: Reusable Function Library for IoT Sensors</h1>
  <!-- <p><code>declare(strict_types=1);</code> is enabled for safer code.</p> -->

  <h2>Readings (°C)</h2>
  <p><?= implode(', ', $sensorReadings) ?></p>

  <h2>All Readings</h2>
<table border="1">
  <tr>
    <th>#</th>
    <th>Celsius (°C)</th>
    <th>Fahrenheit (°F)</th>
    <th>Kelvin (K)</th>
    <th>Above 23°C?</th>
  </tr>
  <?php foreach ($sensorReadings as $i => $reading): ?>
    <tr>
      <td><?= $i + 1 ?></td>
      <td><?= number_format($reading, 2) ?></td>
      <td><?= number_format(celsiusToFahrenheit($reading), 2) ?></td>
      <td><?= number_format(celsiusToKelvin($reading), 2) ?></td>
      <td><?= isAboveThreshold($reading, 23.0) ? 'Yes' : 'No' ?></td>
    </tr>
   <?php endforeach; ?> <!-- in html body need to use endforeach -->
</table>
</body>
</html>