# Write a shell script file named exercise2.sh that makes a list of files in your home
# directory that were changed less than 24 hours ago, but leave out directories.

find ~ -mtime -1 -type f -maxdepth 1 2> /dev/null

# References:

# 1.) https://www.thegeekstuff.com/2009/06/15-practical-unix-linux-find-command-examples-part-2/
# 2.) https://askubuntu.com/questions/350208/what-does-2-dev-null-mean
