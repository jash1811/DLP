%{
#include <stdio.h>
%}

%%
(?i)charusat   { printf("university"); } // Case-insensitive match
.              { putchar(yytext[0]); }  // Print other characters as is
%%

int main() {
    yylex(); // Start lexical analysis
    return 0;
}

int yywrap() {
    return 1;
}
