# Write a shell script which takes filename as argument
# and checks whether file is regular file,directory,block special file
# character special file, named pipe, symbolic link, socket, device file etc.

# If the Number of Arguments are Not Equal to 1, [Invalid Input]
if [ $# -ne 1 ]; then
    echo "Right usage: ./q1.sh <filename>"
    exit 2
fi

# Take File Name from Argument 1
filename=$1

# Display Directory Information Using "ls -ld" and redirect it to temp.txt
ls -ld $filename > temp.txt

# Let "file" hold that temp.txt content
file=temp.txt

# All Details about that File [Modes Author Date Create Name Size]
res=$(cat "$file")

# echo $res

# cut command prints first character of each line from the file.
# -rwxrwxrwx 1 bhagya bhagya 187 Aug 31 15:52 regular_file.txt
# - <- DASH

type=$(echo $res | cut -c1-1)

case $type in
    "-") echo "It is a Regular File." ;;
    "d") echo "It is a Directory." ;;
    "c") echo "It is a Character Device file" ;;
    "l") echo "It is a Symbolic Link." ;;
    "s") echo "It is a Local Socket file." ;;
    "b") echo "It is a Block Device file." ;;
    "p") echo "It is a Named Pipe." ;;
    *) echo "It is not a Valid Type." ;;
esac

# Delete the temp File
rm temp.txt

# References
# 1.) https://www.livefirelabs.com/unix_tip_trick_shell_script/unix_operating_system_fundamentals/file-types-in-unix.htm
# 2.) https://www.computernetworkingnotes.com/linux-tutorials/different-types-of-files-in-linux.html
# 3.) https://www.geeksforgeeks.org/unix-file-system/
# 4.) https://en.wikipedia.org/wiki/Unix_file_types
# 5.) https://www.geeksforgeeks.org/ln-command-in-linux-with-examples/ [Symbolic Links]
# 6.) https://en.wikipedia.org/wiki/Ln_(Unix)
# 7.) https://www.computerhope.com/jargon/s/special-file.htm
# 8.) https://www.geeksforgeeks.org/cut-command-linux-examples/
