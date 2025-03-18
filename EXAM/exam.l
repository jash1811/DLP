%{
#include <stdio.h>
#include <string.h>
#include <ctype.h>
%}

%%
(car|table|fox|dog|day|children|park|noise|everyone|book|eyes) { printf("Common Noun: %s\n", yytext); }
(Jash|India|Microsoft|Google) { printf("Proper Noun: %s\n", yytext); }
(I|we|you|he|she|it|they) { printf("Pronoun: %s\n", yytext); }
(sleep|talk|walk|write|read) { printf("Verb: %s\n", yytext); }
(quickly|slowly|willingly|sadly) { printf("Adverb: %s\n", yytext); }
(beautiful|strong|light|heavy) { printf("Adjective: %s\n", yytext); }
(in|on|under|over|at) { printf("Preposition: %s\n", yytext); }
(and|or|but|nor|so) { printf("Conjunction: %s\n", yytext); }
(oh|wow|oops|alas|hurrah) { printf("Interjection: %s\n", yytext); }
%%

int main() {
    printf("Enter a paragraph:\n");
    yylex(); 
    return 0;
}

int yywrap() {
    return 1;
}
