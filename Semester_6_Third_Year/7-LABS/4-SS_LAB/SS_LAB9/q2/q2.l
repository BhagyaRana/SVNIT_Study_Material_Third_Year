%{

%}

octal [0-7]
hex [0-9A-Fa-f]

%%
({octal})+ {printf("%s is Octal Number [Also a Hexa-Decimal Number]!\n",yytext);}

({hex})+ {printf("%s is Hexa-Decimal Number!\n",yytext);}

%%

int main()
{
    yyin=fopen("input.txt","r");
    yylex();
    return 0;
}