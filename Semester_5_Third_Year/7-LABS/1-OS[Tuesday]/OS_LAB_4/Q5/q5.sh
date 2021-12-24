# Write a non-interactive script that takes in any no. of directory name as argument
# and calculates total no. of blocks of disk space occupied by the ordinary files
# in all the directories.

space=0

for arg in "$@";
do
    # If Argument is Directory
    if [ -d $arg ]; then
        
        # Get all the Files in res
        res=$(find $arg -type f)
        
        # For Each File in Files Available
        for file in $res; do
            
            # Use Long Listing Format and List Only Directories
            ls -ld $file >tmp.txt
            
            fileNew=tmp.txt
            # Copy All the Contents in res
            res=$(cat "$fileNew")
            # Get the First Char in Each Line
            type=$(echo $res | cut -c1-1)
            
            # If it is Regular File
            if [ $type == "-" ]; then
                # du Command -> Disk Utilization {Summarize and Produce a Grand Total}
                # size=$(du -sc $file | tail -n 1 | cut -c1-1) [WRONG]
                # cut -c1-1 -> Will NOT WORK, Since Number Can be Double Digit or More
                size=$(du -sc $file | tail -n 1 | grep -o -E '[0-9]+')
                # echo $size
                
                space=$(($space + $size))
            fi
            
        done
    fi
done

rm tmp.txt

echo "Disk Space Used : $space"

# https://www.codegrepper.com/code-examples/shell/bash+extract+number+from+string