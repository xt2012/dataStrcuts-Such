#!/bin/bash

# justcheck if a file was provided as an argument
if [ "$#" -ne 1 ]; then
    echo "Usage: $0 filename.c"
    exit 1
fi

# get the filename from the first argument
filename="$1"

# check if the file exists
if [ ! -f "$filename" ]; then
    echo "Error: File '$filename' does not exist."
    exit 1
fi

# extract the basename
basename=$(basename "$filename" .c)


gcc -o "$basename" "$filename"
if [ $? -ne 0 ]; then
    echo "Compilation failed."
    exit 1
fi

./"$basename"

