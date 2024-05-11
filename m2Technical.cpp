#include <iostream>
#include <cctype>
using namespace std;

int Menu();
void InputString(int, char*, char*);
void StringLength(char*);
void StringCompare(char*, char*);
void StringConcatenate(char*, char*);
char EndTrail();

int main() {
    int choice;
    char str1[100], str2[100];
    do {
        choice = Menu();
        switch(choice) {
            case 1:
            InputString(choice, str1, nullptr);
            StringLength(str1);
            break;
            case 2:
            InputString(choice, str1, str2);
            StringCompare(str1, str2);
            break;
            case 3:
            InputString(choice, str1, str2);
            StringConcatenate(str1, str2);
            break;
            case 4:
            return 0;
            default:
            return 0;
        }
    } while(EndTrail() == 'Y');
}

int Menu() {
    int choice;
    do {
        cout << "What do you want to do?\n";
        cout << "[1] Find the String Length\n";
        cout << "[2] Compare Two Strings\n";
        cout << "[3] Concatenate Two Strings\n";
        cout << "[4] Exit\n\n";
        cout << "Enter your choice: \n";
        cout << ":: ";
        cin >> choice;
        cin.ignore();
    } while (choice < 0 || choice > 4);
    return choice;
}

void InputString(int choice, char* s1, char* s2){
    if (choice == 1) {
        cout << "Enter a string: ";
        cin.getline(s1, 100);
    } else if (choice == 2 || choice == 3) {
        cout << "Enter the first string: ";
        cin.getline(s1, 100);
        cout << "Enter the second string: ";
        cin.getline(s2, 100);
    }
}

void StringLength(char* s1) {
    int count = 0;
    while(*s1 != '\0') {
        count++;
        s1++;
    }
    cout << "\nLength of the stirng: "  << count << "\n\n";
}

void StringCompare(char* s1, char* s2) {
    int countString1 = 0, countString2 = 0;
    while (*s1 != '\0') {
        countString1++;
        s1++;
    }
    while (*s2 != '\0') {
        countString2++;
        s2++;
    }

    if (countString1 < countString2) {
        cout << "\nString 1 is smaller...\n\n";
    }
    if (countString1 > countString2) {
        cout << "\nString 2 is smaller...\n\n";
    }
    if (countString1 == countString2) {
        cout << "\nBoth strings are equal length...\n\n";
    }

    s1 -= countString1;
    s2 -= countString2;
}

void StringConcatenate(char* s1, char* s2) {
    char* current = s1; 

    while (*current) 
        current++;

    while (*s2) {
        *current = *s2;
        current++;
        s2++;
    }
    *current = '\0'; 

    cout << "\nThe concatenated string:\n" << s1 << "\n\n";
}

char EndTrail() {
    char continueChoice;

    cout << "Do you want to Continue [Y/N]: ";
    cin >> continueChoice;
    continueChoice = toupper(continueChoice);
    return continueChoice;
}

