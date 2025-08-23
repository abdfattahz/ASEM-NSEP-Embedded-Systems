<?php

class Sensor {
    private $id;
    private $name;
    private $type;
    private $location;

public function __construct($id, $name, $type, $location) {
        $this->id = $id;
        $this->name = $name;
        $this->type = $type;
        $this->location = $location;
    }

public function getId() {
        return $this->id;
    }

    public function getName() {
        return $this->name;
    }

    public function getType() {
        return $this->type;
    }

    public function getLocation() {
        return $this->location;
    }

    public function setName($name) {
        $this->name = $name;
    }

    public function setType($type) {
        $this->type = $type;
    }

    public function setLocation($location) {
        $this->location = $location;
    }

}

class temperatureSensor extends Sensor {
    public function __construct($id, $name, $location) {
        parent::__construct($id, $name, "Temperature", $location);
    }
} 

$device1 = new Sensor(1, "Temperature Sensor", "Thermometer", "Living Room");
$device2 = new Sensor(2, "Humidity Sensor", "Hygrometer", "Bathroom");
$device3 = new Sensor(3, "Light Sensor", "Photometer", "Kitchen");

echo $device1->getName() . " is located in " . $device1->getLocation() . "<br>";
echo $device2->getName() . " is located in " . $device2->getLocation() . "<br>";
echo $device3->getName() . " is located in " . $device3->getLocation() . "<br>";
?>