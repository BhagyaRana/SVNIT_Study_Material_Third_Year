%{
int cnt=0;
%}

%%

(aa).*(bcd) {printf("%s : Match Found!",yytext);cnt++;} 

%%

int main()
{
    yyin=fopen("input.txt","r");
    yylex();
    printf("\nNumber of Strings Starting with aa & Ending with bcd are : %d\n",cnt);
    return 0;
}