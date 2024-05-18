#include <iostream>
#include <list>
#include <string>
#include <stack>
using namespace std;

struct Characters{
    string braces;
};


int main () {
    stack<Characters, list<Characters>> curly;
    int closeCount= 0, openCount=0, req=0, strLength;
    string braces;
    Characters character;

    while (true){
        
        cout << "\nEnter a string of braces: ";
        getline(cin, braces);

        strLength = braces.length();
        for (int i=0; i < strLength; i++) {
            char ch = braces[i];
            character.braces = ch;
            curly.push(character);
        }

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

    if (openCount < closeCount) {
        req = closeCount - openCount;
    }
    else {
    req = openCount - closeCount;
    }
    cout << "Minimum number of replacements: " << req;
    req = 0;
    openCount = 0;
    closeCount = 0;
    }
}