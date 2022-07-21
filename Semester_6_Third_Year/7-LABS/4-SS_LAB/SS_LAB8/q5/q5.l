%{
    #include<math.h>   
    int op=0,i;
    double a,b;
    void calculate();
%}

number [0-9]+|([0-9]*)"."([0-9]*)
pow "^"

%%

\+ {op=1;}
[-] {op=2;}
[*] {op=3;}
[/] {op=4;}
{pow} {op=5;}
\n { printf("answer=%f\n",a);}
{number}  {calculate();}

%%

void calculate(){
    if(op==0){
        a=atof(yytext);
    }
    else{
        b=atof(yytext);
        switch(op){
            case 1: a=a+b;
                break;
            case 2: a=a-b;
                break;
            case 3: a=a*b;
                break;
            case 4: a=a/b;
                break;
            case 5: for(i=a;b>1;b--){
                    a=a*i;
            }
                break;
        }
        op=0;
    }
}

int main(){
    yylex();
    return 0;
}
