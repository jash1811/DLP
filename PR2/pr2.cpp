#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    int numStates, numSymbols, initialState, numAcceptingStates;
    vector<int> acceptingStates;
    unordered_map<int, unordered_map<char, int>> transitionTable;

    cout << "Enter the number of states: ";
    cin >> numStates;

    cout << "Enter the number of input symbols: ";
    cin >> numSymbols;
    vector<char> symbols(numSymbols);
    cout << "Enter the input symbols (separated by space): ";
    for (int i = 0; i < numSymbols; ++i) {
        cin >> symbols[i];
    }

    cout << "Enter the initial state: ";
    cin >> initialState;

    cout << "Enter the number of accepting states: ";
    cin >> numAcceptingStates;
    cout << "Enter the accepting states (separated by space): ";
    acceptingStates.resize(numAcceptingStates);
    for (int i = 0; i < numAcceptingStates; ++i) {
        cin >> acceptingStates[i];
    }

    cout << "Enter the transition table (current_state input_symbol next_state):\n";
    int currentState, nextState;
    char inputSymbol;
    for (int i = 0; i < numStates * numSymbols; ++i) {
        cin >> currentState >> inputSymbol >> nextState;
        transitionTable[currentState][inputSymbol] = nextState;
    }

    string inputString;
    cout << "Enter the input string: ";
    cin >> inputString;

    int current = initialState;
    for (char symbol : inputString) {
        if (transitionTable[current].find(symbol) != transitionTable[current].end()) {
            current = transitionTable[current][symbol];
        } else {
            cout << "Rejected: Invalid symbol '" << symbol << "' encountered.\n";
            return 0;
        }
    }

    bool isAccepted = false;
    for (int state : acceptingStates) {
        if (current == state) {
            isAccepted = true;
            break;
        }
    }

    if (isAccepted) {
        cout << "Accepted: Final state is an accepting state.\n";
    } else {
        cout << "Rejected: Final state is not an accepting state.\n";
    }

    return 0;
}
