<?php
$num1 = $argv[1] ?? 1;
$num2 = $argv[2] ?? 2;
$ans = null;

$ans = $num1 + $num2;
echo "Sum of {$num1} + {$num2} = {$ans}" . PHP_EOL;
$ans = $num1 - $num2;
echo "Difference of {$num1} - {$num2} = {$ans}" . PHP_EOL;
$ans = $num1 * $num2;
echo "Product of {$num1} * {$num2} = {$ans}" . PHP_EOL;
$ans = $num1 / $num2;
echo "Division of {$num1} { /$num2} = {$ans}" . PHP_EOL;
$ans = $num1 % $num2;
echo "Modulus of {$num1} % {$num2} = {$ans}" . PHP_EOL;
$ans = $num1 ** $num2;
echo "Exponent of {$num1} ^ {$num2} = {$ans}" . PHP_EOL;
echo "Increment of the first number: " . ++$num1 . PHP_EOL;
echo "Increment of the second number: " . ++$num2 . PHP_EOL;
echo "Decrement of the first number: " . --$num1 . PHP_EOL;
echo "Decrement of the second number: " . --$num2 . PHP_EOL;
echo "Concatenation: " . ($num1 . $num2) . PHP_EOL;
echo "Comparison: " . ($num1 == $num2 ? 'Equal' : 'Not Equal') . PHP_EOL;
echo "Identity: " . ($num1 === $num2 ? 'Identical' : 'Not Identical') . PHP_EOL;
echo "Less than: " . ($num1 < $num2 ? 'True' : 'False') . PHP_EOL;
echo "Greater than: " . ($num1 > $num2 ? 'True' : 'False') . PHP_EOL;
?>