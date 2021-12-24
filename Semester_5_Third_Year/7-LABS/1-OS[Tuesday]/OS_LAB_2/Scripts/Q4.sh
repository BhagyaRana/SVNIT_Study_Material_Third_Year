# (4) Shell Script Program to Count Number of files in a Directory.

#!/bin/bash

printf "Number of Files in Current Directory: "
ls -1q | wc -l

# Reference
# 1.) https://stackoverflow.com/questions/20895290/count-number-of-files-within-a-directory-in-linux
# 2.) https://www.geeksforgeeks.org/practical-applications-ls-command-linux/