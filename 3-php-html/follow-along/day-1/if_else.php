<?php

$temperature = $argv[1];

if ($temperature < 20) {
    echo "Temperature is LOW";
} elseif ($temperature >= 20 && $temperature < 30) {
    echo "Temperature is NORMAL";
} 
else {
    echo "Temperature is HIGH";
}
?>