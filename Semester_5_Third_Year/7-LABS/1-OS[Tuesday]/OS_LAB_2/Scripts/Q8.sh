# (8) Implement simple calculator. Numbers are supplied by command line argument.

#!/bin/bash

# Check for Valid Input

if [ $# -ne 2 ]; then
    echo "2 command line arguments are required"
    exit 2
fi

if ! [[ $1 =~ $re ]]; then
    echo "error: Not a number" >&2
    exit 1
fi

if ! [[ $2 =~ $re ]]; then
    echo "error: Not a number" >&2
    exit 1
fi

# Inputs from User
a=$1
b=$2

echo "Enter Choice :"
echo "1. Addition"
echo "2. Subtraction"
echo "3. Multiplication"
echo "4. Division"

echo "Your Choice : "
read -n1 ch
echo " "

# Switch Case to perform calulator operations
case "$ch" in
    '1')
        res=$(echo $a + $b | bc)
    ;;
    '2')
        res=$(echo $a - $b | bc)
    ;;
    '3')
        res=$(echo $a \* $b | bc)
    ;;
    '4')
        res=$(echo "scale=2; $a / $b" | bc)
    ;;
    *)
        echo "Invalid Choice"
        exit 1
    ;;
esac
echo "Result : $res"

# bc command is used for command line calculator.

# References
# 1.) https://www.geeksforgeeks.org/simple-calculator-bash/