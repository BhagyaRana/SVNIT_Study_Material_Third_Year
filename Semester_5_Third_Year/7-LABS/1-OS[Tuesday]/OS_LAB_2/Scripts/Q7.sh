# (7) Write a shell script to find out biggest number form given three numbers. Numbers are supplied by command line argument.

#!/bin/bash

# Regular Expression for Number
re='^[+-]?[0-9]+?$'

# Input Validation
if ! [[ $1 =~ $re ]]; then
    echo "Error: Input is Not a Valid Number" >&2
    exit 1
fi

if ! [[ $2 =~ $re ]]; then
    echo "Error: Input is Not a Valid Number" >&2
    exit 1
fi

if ! [[ $3 =~ $re ]]; then
    echo "Error: Input is Not a Valid Number" >&2
    exit 1
fi

# Method 1

# Store it in Array for
arr=($1 $2 $3)

# Intializa the First element to be Maximum
max_element=${arr[0]}

# Using ${arr[@]} or ${arr[*]}, we can access the all array elements.
for n in "${arr[@]}";
do
    ((n > max_element)) && max_element=$n
done

echo "Maximum of all 3 Numbers : " $max_element

# Method 2

# if [ $1 -gt $2 ] && [ $1 -gt $3 ]
# then
#     echo "Maximum Element : " $1
# elif [ $2 -gt $1 ] && [ $2 -gt $3 ]
# then
#     echo "Maximum Element : " $2
# else
#     echo "Maximum Element : " $3
# fi