%{
    int vowel=0;
    int consonants=0;
%}

vowel[aeiouAEIOU]
consonant[b-df-hj-np-tv-zB-DF-HJ-NP-TV-Z]

%%

{vowel} {vowel++;}
{consonant} {consonants++;}

%%

int main(){
    yylex();
    printf("Total vowels:%d \nTotal consonants: %d\n",vowel,(consonants));

    return 0;
}
