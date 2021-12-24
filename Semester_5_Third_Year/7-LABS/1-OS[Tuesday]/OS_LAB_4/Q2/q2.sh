# Write a shell script which will take file name as argument and
# check whether the file name is a dir or not and then proceed further only
# if it is a dir, else give usage message.
# The script should then print in the tabular format, name of each sub-dir (within the argument dir) and
# a count of the number of top level files in that sub-dir. Modify the program to work with multiple numbers of arguments, too.

if [ $# -eq 0 ]; then
    echo "Right usage: ./q2.sh [<dirs>,..]"
    exit 2
fi

for filename in "$@";
do
    # If the Given FileName is Directory
    if [ -d "$filename" ];
    then
        # Copy the Contents of File in q2.txt [STEP 1]
        find $filename -depth -maxdepth 1 > q2.txt
        
        # command1 && command2 -> command2 will execute if command1 has executed successfully.
        # If "count.txt" Exist, then Remove it!
        [ -f "count.txt" ] && rm count.txt
        # If "final.txt" Exist, then Remove it!
        [ -f "final.txt" ] && rm final.txt
        
        echo "List of Sub-directories & Count of top level files in $filename"
        
        echo "Directory,Count" >>count.txt
        
        # Read all the Files in Given Folder  {Stored in q2.txt From Step 1}
        while read line;
        do
            if [[ $filename != $line ]]; then
                
                # It will Go inside $line Folder and Count all the Files in it
                count=0
                for entry in "$line"/*;
                do
                    # Increment the Count, If it is File
                    [ -f "$entry" ] && count=$(($count + 1))
                done
                
                # Relative Path of File
                file=$(echo basename $line)
                new="$file,$count"
                
                # Redirect it to "count.txt" File
                $new >> count.txt
            fi
        done < q2.txt
        
        # Method to Read File {count.txt} Line by Line
        while IFS=, read -r a b;
        do
            # File Name & Count redirected to "final.txt"
            echo "$a $b" >>final.txt;
        done < count.txt
        
        # Print in Tabular Form
        awk '{printf "|%-30s|%20s|\n",$1,$2}' final.txt
        echo ""
    else
        echo "$fileName is Not A Directory!"
    fi
done

# Remove all the Text Files Created
rm *.txt

# >,>>, < (Redirection) -> Redirects the output of a command or a group of commands to a file or stream.
# 1.) https://www.cyberciti.biz/faq/unix-howto-read-line-by-line-from-file/