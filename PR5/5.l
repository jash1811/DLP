%{
#include <stdio.h>
#include <ctype.h>
#include <string.h>

void print_token(const char* type, const char* value) {
    printf("%s: %s\n", type, value);
}
%}

%%
"int"|"char"|"float"|"double"|"void"|"return"|"struct"|"long"  { print_token("Keyword", yytext); }
[a-zA-Z_][a-zA-Z0-9_]*    { print_token("Identifier", yytext); }
[=+\-*/]                 { print_token("Operator", yytext); }
[0-9]+                   { print_token("Constant", yytext); }
['\"].*?['\"]            { print_token("String", yytext); }
[{}();,]                 { print_token("Punctuation", yytext); }
"//".*                   { /* Ignore comments */ }
"/*"([^*]|\*+[^*/])*\*+"/" { /* Ignore block comments */ }
[ \t\n]                  { /* Ignore spaces and newlines */ }
.                        { printf("Unknown: %s\n", yytext); }
%%

int main() {
    printf("Enter C code (Ctrl+D to stop):\n");
    yylex();
    return 0;
}

int yywrap() {
    return 1;
}
