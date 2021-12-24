# (6) Write a shell script to add two numbers supplied by user and supplied as command line argument.

#!/bin/bash

# Regular Expression for Number
re='^[+-]?[0-9]+?$'

# Check if Input is Valid
if ! [[ $1 =~ $re ]]; then
    echo "Error: Input is Not a Valid Number" >&2
    exit 1
fi

if ! [[ $2 =~ $re ]]; then
    echo "Error: Input is Not a Valid Number" >&2
    exit 1
fi


echo "Sum of Two Given Numbers : " $(($1 + $2))

# References
# 1.) https://stackoverflow.com/questions/806906/how-do-i-test-if-a-variable-is-a-number-in-bash/806923
