# (5) Shell Script Program to copy contents of one file to another.

#!/bin/bash

#$1 refers to the first argument
#$2 refers the second argument 

file1=$1
file2=$2

if [ -f "$file1" ]; then
    cat $1 >>$2
else
    echo "$file1 Does Not Exist."
fi
