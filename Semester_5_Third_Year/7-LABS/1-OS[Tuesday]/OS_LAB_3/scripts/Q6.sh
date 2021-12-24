echo "Files greater than 1000 bytes : "
find . -maxdepth 1 -type f -size +1000c -ls | sort -r -n -k7
echo "Number of such files : "
find . -maxdepth 1 -type f -size +1000c -ls | sort -r -n -k7 | wc -l

# -maxdepth 1 : find files only in current directory
# -type f : find only files
# -size +1000c : find only files greather than 1000 bytes ("c" = bytes)
# -ls : list them
# -r Option: Sorting In Reverse Order
# -n Option : To sort a file numerically
# -k7 Option : to sort on the seventh column.
# wc -l : To Count the Number of Lines

# References
# 1.) https://unix.stackexchange.com/questions/394672/sort-files-greater-than-1000-bytes-in-descending-order
# 2.) https://www.geeksforgeeks.org/sort-command-linuxunix-examples/