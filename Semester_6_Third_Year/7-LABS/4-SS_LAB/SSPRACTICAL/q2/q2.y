%{
#include<stdio.h>
int flag=0;
%}

%token NUMBER
%left '+' '-'
%left '*' '/' '%'
%left '(' ')'

%%

Expression: E{ printf("\nResult = %d\n",$$);return 0;};

E : E E'+' {$$=$1+$3;}
  | E E'-' {$$=$1-$3;}
  | E E'*' {$$=$1*$3;}
  | E E'/' {$$=$1/$3;}
  | E E'%' {$$=$1%$3;}
  | '('E')' {$$=$2;}
  | NUMBER {$$=$1;};

%%

void main()
{
    printf("\nEnter Expression:\n");

    yyparse();

    if(flag==0)
        printf("\nPostFix Arithematic Expression is Valid\n\n");
}

void yyerror()
{
    printf("\nPostFix Arithematic Expression is Invalid\n\n");
    flag = 1;
}
