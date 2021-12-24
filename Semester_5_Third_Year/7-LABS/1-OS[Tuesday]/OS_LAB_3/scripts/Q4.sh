
# $# -> No of Argument [Count]
if [ $# -ne 2 ]; then
    echo "2 Command Line Arguments Required"
    exit 1
fi

# First Argument: Word
word=$1
# Second Argument: No of Times to be Printed
num=$2

for ((i=0; i < $num;i++ )); do
    echo "$word"
done
