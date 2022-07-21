%{
#include<stdio.h>
int is_valid = 0;
%}

letter [A-Za-z]
digit [0-9]

myfor (for)
id ({_|letter}+)({letter|digit|'_'}+)

openbr '('
closebr ')'
semicln ';'

intial (int)(' ')(letter)('=')({digit}+)
condition (letter)('<'|'>'|'<='|'>='|'!=')(letter|digit)
updation (letter)('++'|'--')

%%

[(myfor)(openbr)({intial}*)(semicln)({condition}+)(semicln)({updation}+)(closebr)] {printf("\nValid FOR Loop!\n");is_valid=1;}

%%

int main()
{
    yyin = fopen("input.txt","r");

    yylex();

    if(!is_valid)
    {
        printf("\nInvalid FOR Loop!\n");
    }

    return 0;
}