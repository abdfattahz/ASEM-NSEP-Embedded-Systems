#!/bin/bash

read -p "Please enter a number between 10 to 20: " num

if [[ num -lt 10 || num -gt 20 ]]; then
  echo "This number is not between 10 to 20"
  exit 1
fi

for ((i = num; i >= 0; i--)); do
  echo $i
done

echo

echo Modified version:
for ((i = num; i >= 0; i--)); do
  if [[ i -ge 3 && i -le 7 ]]; then
    continue
  fi
  echo $i
done
