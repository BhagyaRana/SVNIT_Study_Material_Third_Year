# 3) Write a script that will search for a specific word in all the files
# in the current dictionary and then prompt with the file name in which word is found.

# Check for Invalid Input
if [ $# -ne 1 ]; then
    echo "Right Usage: ./q3.sh <word>"
    exit 2
fi

# Get all Files in files
files=$(find . -type f)

# Get the Word as Argument
word=$1

for file in $files;
do
    res=$(grep -w $word $file)

    # -n -> string {res} is not null
    if [ -n "$res" ]; then
        echo "$file contains word $word"
    fi
done

# Reference
# 1.) https://www.geeksforgeeks.org/grep-command-in-unixlinux/

#  Checking for the whole words in a file : 
# By default, grep matches the given string/pattern even if it found as a substring in a file. 
# The -w option to grep makes it match only the whole words. 
