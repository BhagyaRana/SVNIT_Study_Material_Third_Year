# Write a script to print only the number of executable files
# in each sub-dir of the argument directory specified

if [ $# -ne 1 ]; then
    echo "Right usage: ./q4.sh <dir>"
    exit 2
fi

# Take Directory Name in Variable "name" from Command Line Arguments
name=$1

echo "The Executable Files are : "

find $name -executable -type f

echo "The Number of Executable Files are : "

find $name -executable -type f | wc -l

# References
# 1.) https://superuser.com/questions/38981/how-can-i-find-only-the-executable-files-under-a-certain-directory-in-linux
# wc -l -> Word Count Command => To Count the Number of Lines

# Yep - because the NTFS file system doesn't support the linux permission system,
# linux assumes all text files on NTFS files systems are executable, just in case they are supposed to be.
