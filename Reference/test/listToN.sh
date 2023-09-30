#!/bin/bash

# Read the value of n from the user
read -p "Enter the value of n: " n

# Initialize an empty array
numbers=()

# Loop through the numbers from 1 to n
for (( i=1; i<=n; i++ ))
do
    numbers+=($i)  # Append the current number to the array
done

# Join the array elements with commas
numbers_string=$(IFS=,; echo "${numbers[*]}")

# Copy the array with numbers to the clipboard
echo "$numbers_string" | xclip -selection clipboard

echo "Array copied to the clipboard."

