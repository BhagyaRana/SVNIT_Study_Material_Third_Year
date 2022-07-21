%{
#include<stdio.h>
int flag=0;
%}

%token NUMBER
/* Left Associative */
%left '+' '-'
%left '*' '/' '%'
%left '(' ')'

%%

Expression: E{ printf("\nResult = %d\n", $$);return 0;};

E : E'+'E {$$=$1+$3;}
  | E'-'E {$$=$1-$3;} 
  | E'*'E {$$=$1*$3;}
  | E'/'E {$$=$1/$3;}
  | E'%'E {$$=$1%$3;}
  | '('E')' {$$=$2;}
  | NUMBER {$$=$1;};

%%

//driver code
void main()
{
    printf("\nEnter Expression:\n");

    yyparse();

    if(flag==0)
        printf("\nArithematic Expression is Valid\n\n");
}

void yyerror()
{
    printf("\nArithematic Expression is Invalid\n\n");
    flag=1;
}
