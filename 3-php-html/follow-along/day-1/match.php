<?php

$light = $argv[1] ?? "red";

$action = match($light) {
    "red" => "Stop",
    "yellow" => "Caution",
    "green" => "Go",
    default => "Invalid Light"
};

echo "Light is {$light} -> Action: {$action}" . PHP_EOL;


?>