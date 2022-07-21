%{
int neg = 0;
int zero = 0;
int pos=0;

%}

%%

[0]+ {printf("Zero Number : %s",yytext);zero++;}
^[1-9][0-9]* {printf("Positive Number : %s",yytext);pos++;}
[-][0-9]+ {printf("Negative Number : %s",yytext);neg++;}

%%

int main()
{
    yyin=fopen("input.txt","r");
    yylex();
    printf("\nNumber of Positive Numbers : %d\n",pos);
    printf("Number of Zero's : %d\n",zero);
    printf("Number of Negative Numbers : %d\n",pos);
    return 0;
}