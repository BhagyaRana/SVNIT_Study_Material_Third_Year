# (16) Find out number of characters, words and lines from a given file.

#! /bin/bash

# Using WC command
# Using wc command the number of words, number of lines, number of white spaces, etc can be determined.

if [ -f "$1" ]; then
    words=$(cat $1 | wc -w)
    chars=$(cat $1 | wc -c)
    line=$(cat $1 | wc --lines)
    echo Number of Characters in $1 is $chars
    echo Number of Words in $1 is $words
    echo Number of Lines in $1 is $line
else
    echo "Error : $1 File Does Not Exist!"
fi

# References
# 1.) https://www.lostsaloon.com/technology/how-to-count-characters-words-and-lines-in-a-file-in-linux/