#!/bin/bash

echo "Enter n -> Number of Users Logged In"
echo "Enter c -> Calendar of current year"
echo "Enter d -> Date"

read choice
echo ""

case "$choice" in
    'n')
        # Counting unique logins when *who* doesn't have a --count flag.
        users=$(who | sort --key=1,1 --unique | wc --lines)
        echo "Number of Users Logged in: " $users
    ;;
    'c')
        # cal : Shows current month calendar on the terminal with the current date highlighted.
        cal -y
    ;;
    'd')
        # date command is used to display the system date and time
        date
    ;;
    *)
        echo "Please Enter a Valid Character"
    ;;
esac

# References:
# 1.) https://stackoverflow.com/questions/28208069/linux-bash-script-to-determine-number-of-users-logged-in
# 2.) https://www.geeksforgeeks.org/cal-command-in-linux-with-examples/
# 3.) https://www.geeksforgeeks.org/date-command-linux-examples/