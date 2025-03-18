%{
#include <stdio.h>

int char_count = 0, word_count = 0, line_count = 0;
%}

%%
\n          { line_count++; char_count++; }  // Count new lines
[ \t]+      { char_count++; }               // Count spaces/tabs
[A-Za-z0-9]+ { word_count++; char_count += yyleng; } // Count words and characters
.           { char_count++; }               // Count other characters
%%

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        printf("Error: Could not open file %s\n", argv[1]);
        return 1;
    }

    yyin = file;
    yylex(); // Start lexical analysis
    fclose(file);

    printf("Characters : %d\n", char_count);
    printf("Words : %d\n", word_count);
    printf("Lines : %d\n", line_count);

    return 0;
}

int yywrap() {
    return 1;
}
