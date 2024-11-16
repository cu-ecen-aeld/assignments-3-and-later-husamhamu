#!/bin/bash

# Check if the required arguments are provided
if [ "$#" -ne 2 ]; then
    echo "Error: Two arguments are required."
    echo "Usage: $0 <file_path> <text_string>"
    exit 1
fi

# Assign arguments to variables
writefile=$1
writestr=$2

# Create the directory path if it does not exist
mkdir -p "$(dirname "$writefile")"

# Write the string to the file, overwriting if it exists
echo "$writestr" > "$writefile" 2>/dev/null

# Check if the file was successfully created
if [ $? -ne 0 ]; then
    echo "Error: Could not create or write to file $writefile"
    exit 1
fi

echo "Successfully wrote to $writefile"
