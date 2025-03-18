%{
#include <stdio.h>
%}

%%
[0-9]+   { printf("%s\n", yytext); }
.        { /* Ignore other characters */ }
%%

int main() {
    yylex();  // Run lexical analysis
    return 0;
}
int yywrap() {
    return 1;
}


// flex obj1.l
// gcc lex.yy.c -o lexer.exe -lfl
// lexer.exe
