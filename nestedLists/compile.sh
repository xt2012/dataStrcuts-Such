#!/bin/bash

# Check if a file was provided as an argument
if [ "$#" -ne 1 ]; then
    echo "Usage: $0 filename.c"
    exit 1
fi

# Get the filename from the first argument
filename="$1"

# Check if the file exists
if [ ! -f "$filename" ]; then
    echo "Error: File '$filename' does not exist."
    exit 1
fi

# Extract the base name (without extension) of the file
basename=$(basename "$filename" .c)

# Compile the C file
gcc -o "$basename" "$filename"
if [ $? -ne 0 ]; then
    echo "Compilation failed."
    exit 1
fi

# Run the compiled executable
./"$basename"

