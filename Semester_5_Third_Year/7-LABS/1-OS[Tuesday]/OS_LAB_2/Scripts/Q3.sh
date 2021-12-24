# (3) Shell Script Program to check whether given file is a directory or not.

#!/bin/bash

FILE_NAME=$1

if [ -d "${FILE_NAME}" ];
then
    echo "${FILE_NAME} is a Directory"
elif [ -f "${FILE_NAME}" ]; then
    echo "${FILE_NAME} is a File"
else
    echo "${FILE_NAME} is Not Valid File/Directory"
    exit 1
fi