#!/bin/bash

read -p "Enter a File name: " file
echo "Number of blank space in $file is: "

# Method 1
grep -c "^$" $file

# References
# 1.) https://tuxthink.blogspot.com/2012/01/couting-number-of-blank-lines-in-file.html