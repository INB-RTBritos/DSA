#include <iostream>
using namespace std;

int main() {
    int *ptr1, *ptr2;

    ptr1 = new int;
    

    *ptr1 = 25;

    cout << "Address pointed in ptr 1 " << ptr1 << endl;
    cout << "value in ptr 1 " << *ptr1 << endl;

    ptr2 = ptr1;
    
    cout << "Address pointed in ptr 2 " << ptr2 << endl;
    cout << "value in ptr 2 " << *ptr2 << endl;

    ptr1 = new int;

    *ptr1 = 23;
    cout << "Address pointed in ptr 1 " << ptr1 << endl;
    cout << "value in ptr 1 " << *ptr1 << endl;
}