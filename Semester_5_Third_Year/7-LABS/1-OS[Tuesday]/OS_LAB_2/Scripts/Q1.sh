# Shell script Program to accept a character and check whether it is an 
# •	Lower case alphabet 
# •	Upper case alphabet 
# •	A digit 
# •	Special symbol 
# •	Vowel 

# Path to Intepretor
#! /bin/bash

# Prompt the User to Read a Character 
read -p "Enter One Character : " USER_CHAR

case $USER_CHAR in
    "A") echo "$USER_CHAR is UPPER case Vowel Alphabet";;
    "E") echo "$USER_CHAR is UPPER case Vowel Alphabet";;
    "I") echo "$USER_CHAR is UPPER case Vowel Alphabet";;
    "O") echo "$USER_CHAR is UPPER case Vowel Alphabet";;
    "U") echo "$USER_CHAR is UPPER case Vowel Alphabet";;
    "a") echo "$USER_CHAR is lower case Vowel Alphabet";;
    "e") echo "$USER_CHAR is lower case Vowel Alphabet";;
    "i") echo "$USER_CHAR is lower case Vowel Alphabet";;
    "o") echo "$USER_CHAR is lower case Vowel Alphabet";;
    "u") echo "$USER_CHAR is lower case Vowel Alphabet";;
    [[:digit:]]) echo "$USER_CHAR is Digit";;
    [[:upper:]]) echo "$USER_CHAR is UPPER case Alphabet" ;;
    [[:lower:]]) echo "$USER_CHAR is lower case Alphabet" ;;
    *) echo "$USER_CHAR is Special symbol"  ;;
esac




