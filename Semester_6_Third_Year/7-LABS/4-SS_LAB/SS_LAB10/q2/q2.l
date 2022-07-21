%{
#include "y.tab.h"
%}

%%

"if" {return IF;}

[sS][0-9]* {return S;}

"<"|">"|"=="|"<="|">="|"!=" {return RELOP;}

[0-9]+ {return NUMBER;}

[a-z][a-zA-Z0-9_]* {return ID;}

\n {return NL;}

. {return yytext[0];}

%%