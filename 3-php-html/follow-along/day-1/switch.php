<?php

$day = $argv[1];

switch ($day) {
    case "Mon" :
        echo "Start of the week";
        break;
    case "Wed" :
        echo "Midweek checkpoint";
        break;
    case "Fri" :
        echo "Weekend is near";
        break;
    case "Sun" :
        echo "End of the week";
        break;
    case "Tue" :
        echo "Another day in the week";
        break;
    default :
        echo "Just another day";
        break;
}