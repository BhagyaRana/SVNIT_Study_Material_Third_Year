# (13) Find the factorial value of given input number.

#! /bin/bash

read -p "Enter Number: " num

re='[0-9]'

if ! [[ $num =~ $re ]]; then
    echo "Error : Not A Valid Number for Factorial" >&2
    exit 1
fi

fact=1

while [ $num -gt 1 ]; do
    fact=$((fact * num))
    num=$((num - 1))
done

# echo "Factorial of Given Number is : $fact"

# Limitation : It can Only Calculate Small Factorial

# For Solving the Limitation :

# echo 'define f(x) {if (x>1){return x*f(x-1)};return 1} f(50)' | bc

# References
# 1.) https://stackoverflow.com/questions/3394580/how-do-you-find-the-factorial-of-a-number-in-a-bash-script