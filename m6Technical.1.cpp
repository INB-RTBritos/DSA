#include<iostream>
using namespace std;

void NumberFrequency(int[], int, int);

int main() {
    int arr[] = {1, 2, 2, 3, 4, 4, 4, 5, 5};
    int size = sizeof(arr) / sizeof(int);

    NumberFrequency(arr, size, 0);
}

void NumberFrequency(int arr[], int size, int index) {
    int count;
    if (index==size)
    return;

    count = 1;
    while (index < size-1 && arr[index] == arr[index+1]) {
        count++;
        index++;
    }

    cout << arr[index] << " appears " << count << " time(s) \n";

    NumberFrequency(arr, size, index + 1);
}

