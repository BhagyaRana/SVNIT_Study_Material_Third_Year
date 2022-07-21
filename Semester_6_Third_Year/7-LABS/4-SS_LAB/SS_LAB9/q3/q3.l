%{
int single = 0;
int multi = 0;

%}

%%

\/\/(.*) {printf("Single Line Comment!\n");single++;}
"/*"([^*]|\*+[^*/])*\*+"/" {printf("Multi Line Comment!\n");multi++;}

%%

int main()
{
    yyin=fopen("input.txt","r");
    yylex();
    printf("Number of Single Line Comments : %d\n",single);
    printf("Number of Multi Line Comments : %d\n",multi);
    return 0;
}