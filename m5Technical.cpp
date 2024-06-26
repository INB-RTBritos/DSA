#include <iostream>
using namespace std;

#define MAX_SIZE 100

class Queue {
    private:
    int front, rear, size;
    int arr[MAX_SIZE];

    public:
    Queue() {
        front = rear = -1;
        size = 0;
    }
    bool isEmpty() {
        if (size == 0)
        return true;
        else
        return false;
    }
    bool isFull() {
        if (size == MAX_SIZE)
        return true;
        else 
        return false;
    }
    void Enqueue(int x) {
        if (isFull()) {
            cout << "Error: Queue is full!\n";
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        }
        else {
            rear++;
        }
        arr[rear] = x;
        size++;
    }
    int Dequeue() {
        int x;
        if (isEmpty()) {
            cout << "Error: Queue is empty!\n";
            return -1;
        }
        x = arr[front];
        if (front == rear) {
            front = rear = -1;
        }
        else {
            front++;
        }
        size--;
        return x;
    }
    int GetSize() {
        return size;
    }
    void DisplayQueue() {
        int i;
        if (isEmpty()){
            cout << "Error: Queue is empty!\n";
            return;
        }
        i = front;
        while (i <= rear) {
            cout << arr[i] <<"\n";
            i++;
        }
    }

    int GetFront() {
        if (isEmpty()) {
            cout << "Error: Queue is empty!\n";
            return -1;
        }
        return arr[front];
    }
};

int main() {
    Queue q;
    q.Enqueue(5);
    q.Enqueue(10);
    q.Enqueue(15);
    q.Enqueue(20);

    q.DisplayQueue();
    cout << "\nFront Element: " << q.GetFront() << "\n\n";

    q.Dequeue();
    q.Dequeue();
    
    q.DisplayQueue();
    cout << "\nFront Element: " << q.GetFront() << "\n\n";
    
}