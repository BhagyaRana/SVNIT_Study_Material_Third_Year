#! /bin/bash

# User Need to Change this Input 
arr=(15 71 120 7 3 35)

n=${#arr[@]}
echo "Original Number(s) in Array : "

for x in "${arr[@]}";
do
    printf "$x "
done

echo ""

for ((i = 0; i < ${#arr[@]}; i++));
do
    for ((j = 0; j < ${#arr[@]}; j++));
    do
        if [[ ${arr[$j]} -lt ${arr[$i]} ]]; then
            tmp=${arr[$i]}
            arr[$i]=${arr[$j]}
            arr[$j]=${tmp}
        fi
    done
done

echo ""

echo "Final Number(s) of Array [Descending] : "
i=0
while [ $i -lt $n ];
do
    printf "${arr[i]} "
    i=$((i + 1))
done

echo ""

# Limitation: Works Only for Positive Numbers