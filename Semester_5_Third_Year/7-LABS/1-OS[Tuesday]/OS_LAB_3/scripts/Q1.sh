# 1) Write a shell script, which finds the prime factors of a given number.

read -p "Enter Number whose Prime Factors Needs to be Found : " no

# Invalid Input [Negative Numbers]
if [ $n -lt 1 ]; then
    echo "Only Positive Numbers Allowed!"
    exit 1
fi

# Special Case of 1
if [ $n0 -eq 1 ]; then
    echo "1 is Unit. It has No Prime Factors!"
    exit 1
fi

echo "The Prime Factors of $no are:"

for ((i = 2; i <= $no; i++));
do
    while [ $((no % $i)) == 0 ];
    do
        echo $i
        no=$((no / $i))
    done
done