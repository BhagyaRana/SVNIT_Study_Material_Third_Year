#!/bin/bash
# [U19CS012 BHAGYA VINOD RANA]

# read -a => Array which will have the Output of top.. command
read -a arr <<< `top -bn1 | grep "%Cpu(s)"`

User_CPU_Time=${arr[1]}
# arr[2] => us, Which is of no use
System_CPU_Time=${arr[3]}

# bc is used for inline calculator in linux
Total_CPU_Time=`echo $User_CPU_Time + $System_CPU_Time | bc`

echo "Total_CPU_Usage : $Total_CPU_Time%"

# Set the Limits for Demarcation of States
upper_limit=70.0
lower_limit=30.0

# If the Total Usage is Greater than 70%, then its Overloaded
if [ $(echo "$Total_CPU_Time > $upper_limit" | bc) -eq 1 ]; then
    echo "Your System State :  Overloaded"
# Else if Total Usage is Less than 30%, then its Lightly Loaded
elif [ $(echo "$Total_CPU_Time < $lower_limit" | bc ) -eq 1 ]; then
    echo "Your System State :  Lightly-Loaded"
# Else Moderately Loaded
else
    echo "Your System State : Moderately Loaded"
fi