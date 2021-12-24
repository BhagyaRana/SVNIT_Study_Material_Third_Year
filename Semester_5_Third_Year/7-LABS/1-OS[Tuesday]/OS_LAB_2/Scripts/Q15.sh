# (15) Display all even numbers within given range.

#! /bin/bash

read -p "Enter Lower Limit of Range : " first
read -p "Enter Upper Limit of Range : " second

# Approach 1 : Brute Force

for ((i = $first; i <= $second; ++i));
do
    rem=$((i % 2))
    if [ "$rem" -eq "0" ]; then
        echo $i
    fi
done

# Approach 2 : Since Modulus is Costly Operation

rem2=$((first % 2))

if [ "$rem2" -eq "1" ]; then
    ((first++))
fi

for ((i = $first; i <= $second; i+=2));
do
    echo $i
done
