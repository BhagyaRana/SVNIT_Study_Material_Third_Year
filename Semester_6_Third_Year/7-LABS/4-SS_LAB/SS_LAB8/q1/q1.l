%{
    #include<stdio.h>
    int wcount=0;
    int lcount=0;
    int ccount=0;
%}

digit[0-9]
letter[a-zA-Z]

%%
\n  {lcount++;}
({letter}|{digit})+  {wcount++; ccount+=yyleng;}
[ ] ccount++;

%%


int main(){
    yyin=fopen("input.txt","r");
    yylex();
    printf("\ntotal word count:%d\n",wcount);
    printf("total line count:%d\n",lcount);
    printf("total character count:%d\n",ccount);
    return 0;
}