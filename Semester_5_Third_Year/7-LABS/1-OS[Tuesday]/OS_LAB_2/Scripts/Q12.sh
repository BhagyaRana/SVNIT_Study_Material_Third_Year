# (12) Write a shell script to print sum of all digits of a given number.

#!/bin/bash

read -p "Enter Number : " num

# Intialize the Sum = 0
sum=0

while [ $num -gt 0 ];
do
    digit=$((num % 10))
    sum=$((sum + digit))
    num=$((num / 10))
done

echo "Sum of Digits of Number : $sum"