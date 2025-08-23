<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Variadic Function Example</title>
</head>
<body>
    <h1>Variadic Function Example</h1>
    <p>This example demonstrates how to use a variadic function in PHP.</p>
    <pre>
    <?php
    function sum(...$numbers) {
        $total = 0;
        foreach ($numbers as $number) {
            $total += $number;
        }
        return $total;
    }

    $result= sum(1, 2, 3);
    echo "The Sum of num is  $result ";
    ?>
    </pre>
</body>
</html>