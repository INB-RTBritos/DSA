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
        if (isEmpty()){
            cout << "Error: Queue is empty!\n";
            return;
        }
        for (int i = front; i <= rear; i++) {
            cout<<arr[i]<<"\n";
        }
    }

    int GetFront() {
        int x;
        if (isEmpty()) {
            cout << "Error: Queue is empty!\n";
            return -1;
        }
        x = arr[front];
        return x;
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