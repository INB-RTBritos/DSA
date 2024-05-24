#include <iostream>
#include <list>
#include <string>
#include <stack>
using namespace std;

struct Characters{
    string braces;
};

void InputBraces(string&);
void PushBraces(stack<Characters, list<Characters>>&, string);
void CountBraces(stack<Characters, list<Characters>>&, int&, int&);
int ReplacementCount(int, int);


int main () {
    stack<Characters, list<Characters>> curly;
    int closeCount= 0, openCount=0, req;
    string bracesHolder;
    Characters character;

    while (true) {
    InputBraces(bracesHolder);
    if (bracesHolder == "-") break;
    PushBraces(curly, bracesHolder);
    CountBraces(curly, openCount, closeCount);
    req = ReplacementCount(openCount, closeCount);

    cout << "Minimum number of replacements: " << req << endl;

    openCount = 0;
    closeCount = 0;
    }
}

void InputBraces(string& bracesHolder) {
    cout << "\nEnter a string of braces: ";
    getline(cin, bracesHolder);
}

void PushBraces(stack<Characters, list<Characters>>& curly, string braces) {
    int strLength;
    Characters character;

    strLength = braces.length();
        for (int i=0; i < strLength; i++) {
            char ch = braces[i];
            character.braces = ch;
            curly.push(character);
    }
}

void CountBraces(stack<Characters, list<Characters>>& curly, int& openCount, int& closeCount) {
    Characters character;

        while (!curly.empty()) {
        character = curly.top();
        if (character.braces == "{") {
            openCount++;
            curly.pop();
        }
        else if (character.braces == "}"){
            closeCount++;
            curly.pop();
        }
    }
}

int ReplacementCount(int openCount, int closeCount) {
    if (openCount < closeCount) 
    return closeCount - openCount;
    else 
    return openCount - closeCount;
}

