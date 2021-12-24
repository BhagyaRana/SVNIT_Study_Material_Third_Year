# Write a shell script, which prints good morning or good evening depending on the login time of the user.

hour=$(date +%H)

if [ $hour -lt 12 ]; then
    echo "Good Morning"
elif [ $hour -lt 16 ]; then
    echo "Good Afternoon"
elif [ $hour -lt 20 ]; then
    echo "Good Evening"
else
    echo "Good Night"
fi
