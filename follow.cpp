#include <iostream>
using namespace std;

int main() {
    string *names;
    int size;

    cout << "How many name?: ";
    cin >> size;
    cin.ignore();
    
    names = new string[size];

    for (int i = 0; i < size; i++) {
        cout << "Enter name # " << i + 1 << ": ";
        getline(cin, names[i]);
    }

    cout << "\n\nNames:\n" << endl;

    for (int j=0; j < size; j++) {
        cout << names[j] << endl;
    }
}
    