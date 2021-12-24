# (11) Write a shell script to print given number in reverse order.

#! /bin/bash

# Method 1

# Number can be Treated as String
read -p "Enter a Number: " num
echo $num | rev


# Method 2

# echo "Enter a Number : "
# read n

# digit=0
# rev=0

# while [ $n -gt 0 ]
# do
#     digit=$(( $n % 10 ))
#     # Left Shift Old Answer and Add the Current Digit to it
#     rev=`expr $rev \* 10 + $digit`
#     n=$(( $n / 10 ))
# done

# echo "Reverse Number : $rev"

# References
# 1.) https://unix.stackexchange.com/questions/65913/print-given-number-in-reverse-order/65924