# 2) Print out all the divisors of Number

read -p "Enter A Number whose Divisors need to be Found : " num

# Only Positive Numbers Allowed
if [ $num -lt 1 ]; then
    echo "Only Positive Numbers Allowed!"
    exit 1
fi

printf "The divisors of $num are: "

for ((i=1; i <= $num; i++)); do
    if [ $(expr $num % $i) -eq 0 ]; then
        echo -n "$i "
    fi
done
echo ""