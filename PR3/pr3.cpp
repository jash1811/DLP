#include <bits/stdc++.h>
using namespace std;

void analyzeCode(const string& filename) {
    ifstream inputFile(filename);
    if (!inputFile) {
        cerr << "Error: Unable to open file." << endl;
        return;
    }

    string line;
    regex tokenRegex("\\b[a-zA-Z_][a-zA-Z0-9_]*\\b");
    regex lexicalErrorRegex("\\b\\d+[a-zA-Z]+\\b");

    cout << "Analyzing code from file: " << filename << endl;

    while (getline(inputFile, line)) {
        cout << "\nLine: " << line << endl;
        cout << "Tokens: ";
        auto tokensBegin = sregex_iterator(line.begin(), line.end(), tokenRegex);
        auto tokensEnd = sregex_iterator();

        for (auto it = tokensBegin; it != tokensEnd; ++it) {
            cout << it->str() << " ";
        }
        cout << endl;

        cout << "Lexical Errors: ";
        auto errorsBegin = sregex_iterator(line.begin(), line.end(), lexicalErrorRegex);
        auto errorsEnd = sregex_iterator();

        if (errorsBegin == errorsEnd) {
            cout << "None";
        } else {
            for (auto it = errorsBegin; it != errorsEnd; ++it) {
                cout << it->str() << " ";
            }
        }
        cout << endl;
    }

    inputFile.close();
}

int main() {
    string filename = "que.c";
    ofstream outputFile(filename);
    if (!outputFile) {
        cerr << "Error: Unable to create file." << endl;
        return 1;
    }
    outputFile << "int main(){\n";
    outputFile << "int a=5,7H;\n"; 
    outputFile << "//assign value\n";
    outputFile << "char b='x';\n";
    outputFile << "/return\nvalue/\n"; 
    outputFile << "return a+b;\n";
    outputFile << "}";

    outputFile.close();
    analyzeCode(filename);

    return 0;
}
