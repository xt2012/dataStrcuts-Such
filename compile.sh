#!/bin/bash

# check if a file was provided as an argument
if [ "$#" -ne 1 ]; then
    echo "Usage: $0 filename.c"
    exit 1
fi

# filename = first arg
filename="$1"

# existence?
if [ ! -f "$filename" ]; then
    echo "Error: File '$filename' does not exist."
    exit 1
fi

# extract that stuff
basename=$(basename "$filename" .c)


#produce  debugging  information  in  the  operating system's native
#format (stabs, COFF, XCOFF, or DWARF). GDB  can  work  with  this
#debugging information.

gcc -o "$basename.o" "$filename" -Wall -Og -fstack-protector-all
if [ $? -ne 0 ]; then
    echo "Compilation failed."
    exit 1
fi


./"$basename.o"

