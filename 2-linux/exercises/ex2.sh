#!/bin/bash

read -p "Please input your Currents (Amp) value: " i
read -p "Please input your Resistor (Ohm) value: " r

v=$(expr $i \* $r)
echo "Your Voltage (V) is: $v"
p=$(expr $i \* $v)
echo "The Power (P) dissipated is: $p"
