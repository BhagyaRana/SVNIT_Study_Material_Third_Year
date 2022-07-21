%{
#include<stdio.h>
#include<stdlib.h>
int count=0;
%}

%token IF RELOP S NUMBER ID NL

%%
stmt: if_stmt NL {printf("No. of Nested IF Statements = %d\n",count); exit(0);} 

;
if_stmt : IF'('cond')''{'if_stmt'}' {count++;} 
        | S
;
cond: x RELOP x 
;
x : ID | NUMBER
;

%%

int yyerror(char *msg)
{
    printf("The Statement is Invalid\n");
    exit(0);
}

void main()
{
    printf("Enter the Statement : \n");

    yyparse();
}