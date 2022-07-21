%%

[a-zA-Z_.0-9]+[@][a-zA-Z.]+[.][a-zA-Z]+ {printf("\n Valid Email\n");}
  
.+ {printf("\nInvalid Email\n");}

%%

int main(){
    yylex();
    return 0;
}