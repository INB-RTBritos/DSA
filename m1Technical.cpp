#include <iostream>
#include <iomanip>
using namespace std;

#define Splitter() cout << setw(90) << setfill('-') << " \n\n";

class Array1D {
    private: 
    int capacity;
    int size;
    int *array;

    public:
    Array1D(int ArrayCap=10);
    ~Array1D() {delete [] array;};
    int GetSize();
    bool isEmpty() const;
    bool isFull() const;
    void InsertItem(int pos, int val);
    void RemoveItem(int pos);
    void AddItem(int val);
    void DisplayElements();
};

int main() {
    Array1D arr(5);
    arr.AddItem(10);
    arr.AddItem(20);
    arr.AddItem(30);
    arr.DisplayElements();
    arr.InsertItem(1, 15);
    arr.DisplayElements();
    arr.AddItem(40);
    arr.DisplayElements();
    arr.AddItem(50);
    arr.RemoveItem(0);
    arr.DisplayElements();
    cout << "Array size: " << arr.GetSize() << endl;
    if (arr.isEmpty())
    {
        cout << "Array is empty!" << endl;
    }
    else
     {
        cout << "Array is not empty!" << endl;
    }


}

Array1D::Array1D(int ArrayCap) {
    capacity = ArrayCap;
    size = 0;
    array = new int[capacity];
}

int Array1D::GetSize() {
    int count;
    for (int i = 0; i > array[capacity]; i++){
        count++;
    }
    return (sizeof(count)*size) / sizeof(int);
}

bool Array1D::isEmpty() const {
    if (size == 0) 
        return true;
    else 
        return false;
}

bool Array1D::isFull() const {
    if (size == capacity) 
        return true;
    else 
        return false;
}

void Array1D::AddItem(int val) {
    if (isFull()) {
        cout << "Array is full. Cannot add anymore" << endl;
        return;
    }

    array[size] = val;
    size = GetSize() + 1;
}

void Array1D::DisplayElements() {
    for (int i = 0; i < size; i++) {
        cout << "Element #  " << i + 1 << " : "  << array[i] << endl << endl;
    }
    Splitter();
}

void Array1D::InsertItem(int pos, int val) {
    if (isFull()) {
        cout << "Array is Full. Cannot insert anymore elements" << endl << endl;
        return;
    }

    if (pos < 0 || pos > size) {
        cout << "Invalid position" << endl;
        return;
    }

    for (int i = size; i > pos; i--) {
        array[i] = array[i-1];
    }
    array[pos] = val;
    size = GetSize() + 1;
}

void Array1D::RemoveItem(int pos) {
    if (isEmpty()) {
        cout << "The Array is Currently Empty. Cannot remove any Elements" << endl;
        return;
    }

    if (pos < 0 || pos > size) {
        cout << "The position you want to access does not exist." << endl;
        return;
    }

    for (int i = pos; i < size; i++) {
        array[i] = array[i+1];
    }

    size = GetSize() - 1;
}