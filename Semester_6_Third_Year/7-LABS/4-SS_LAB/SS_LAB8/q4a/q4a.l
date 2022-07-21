%%

[+][0-9]{1,3}[1-9][0-9]{9} {printf("\nMobile Number Valid\n");}
  
.+ {printf("\nMobile Number Invalid\n");}

%%

int main(){
    yylex();
    return 0;
}