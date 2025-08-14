<?php

// ANSI color codes
const RED    = "\033[31m";
const GREEN  = "\033[32m";
const YELLOW = "\033[33m";
const BLUE   = "\033[34m";
const RESET  = "\033[0m";


$temp = $argv[1];
$temp2 = $argv[2] ?? $temp;

if ($temp < 20) {
   echo "OFF" . PHP_EOL;
   echo "OFF" . PHP_EOL . PHP_EOL;
} elseif ($temp < 30 ) {
   echo GREEN . "ON (Green Light)" . RESET . PHP_EOL;
   echo "ON (Low Speed)" . PHP_EOL . PHP_EOL;
} elseif ($temp < 40 ) {
   echo YELLOW . "ON (Yellow Light)" . RESET . PHP_EOL;
   echo "ON (Medium Speed)" . PHP_EOL . PHP_EOL;
} elseif ($temp > 40 ) {
   echo RED . "ON (Red Light)" . RESET . PHP_EOL;
   echo "ON (High Speed)" . PHP_EOL . PHP_EOL;
}

$state = match(true) {
    $temp2 < 20 => ["LED" => "OFF", "Fan" => "OFF"],
    $temp2 < 30 => ["LED" => GREEN  . "ON (Green Light)"   . RESET, "Fan" => "Low Speed"],
    $temp2 < 40 => ["LED" => YELLOW . "ON (Yellow Light)"  . RESET, "Fan" => "Medium Speed"],
    $temp2 >= 40 => ["LED" => RED   . "ON (Red Light)"     . RESET, "Fan" => "High Speed"],
    default => ["LED" => "Invalid", "Fan" => "Invalid"],
};

echo "Temperature is {$temp2}°C -> LED: {$state['LED']}, Fan: {$state['Fan']}" . PHP_EOL;

?>