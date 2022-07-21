%{
    #include<stdio.h>
%}

lower[a-z]
upper[A-Z]
%%

{lower} { printf("%c",yytext[0]-32);}
{upper} {printf("%c",yytext[0]);}
. {printf("%c",yytext[0]);}

%%

int main(){
    yylex();
    return 0;
}