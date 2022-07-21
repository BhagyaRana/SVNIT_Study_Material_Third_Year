%{

%}

alphabet [a-zA-Z]
digit [0-9]

%%

asm|double|new|switch|auto|else|operator|template|break|enum|private|this|case|extern|protected|throw|catch|float|public|try|char|for|register|typedef|class|friend|return|union|const|goto|short|unsigned|continue|if|signed|virtual|default|inline|sizeof|void|delete|int|static|volatile|do|long|struct|while { printf("%s is Reserved Keyword (C/C++)!\n",yytext);}

([_]|({alphabet}))([_]|({alphabet})|({digit}))* { printf("%s is Valid Identifier!\n",yytext);}

({digit})+|(({digit})+[.]({digit})+) { printf("%s is Valid Constant!\n",yytext);}

["](.)*["] {printf("%s is String Constant!\n",yytext);}
[']({alphabet})*['] {printf("%s is String Constant!\n",yytext);}

%%

int main()
{
    yyin=fopen("input.txt","r");
    yylex();
    return 0;
}