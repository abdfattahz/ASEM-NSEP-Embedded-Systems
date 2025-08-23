#!/bin/bash

file1="file1.txt"
file2="file2.txt"

#len1=$(wc -m <"$file1")
#len2=$(wc -m <"$file2")

len1=$(wc -m $file1 | cut -d" " -f1)
len2=$(wc -m $file2 | cut -d" " -f1)

if [ "$len1" -gt "$len2" ]; then
  echo $file1
  cat file1.txt
else
  echo $file2
  cat file2.txt
fi

if grep -q "mango" "$file1"; then
  echo Fruit
fi

if grep -q "dog" "$file1"; then
  echo Pet
fi
