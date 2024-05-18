#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node* next;
};

class LinkedList {
    private:
        Node* head;
        int size;
    public:
        LinkedList() {
            head = NULL;
            size = 0;
        }
    void InputData(int&);
    void InsertAtBeginning(int);
    void InsertAtPosition(int);
    void InsertAtEnd(int);
    void RemoveAt();
    bool Search(int);
    int GetSize();
    bool IsEmpty();
    bool IsFull();
    void PrintList();
};

int Menu();

int main() {
    LinkedList list;
    int dataHolder;

    do {
        switch (Menu()) {
            case 1:
            list.InputData(dataHolder);
            list.InsertAtBeginning(dataHolder);
            break;
            case 2:
            list.InputData(dataHolder);
            list.InsertAtEnd(dataHolder);
            break;
            case 3:
            list.InputData(dataHolder);
            list.InsertAtPosition(dataHolder);
            break;
            case 4:
            list.RemoveAt();
            break;
            case 5:
            list.InputData(dataHolder);
            if (list.Search(dataHolder))
                cout << "Element found in the list\n";
            else 
                cout << "Element is not found in the list\n";
            break;
            case 6:
            list.PrintList();
            break;
            case 7:
            cout << "The size of the list is: " << list.GetSize() << "\n";
            break;
            case 8:
            if(list.IsEmpty()) 
                cout << "List is empty\n";
            else 
                cout << "List is not empty\n";
            break;
            case 9:
            if(list.IsFull()) 
                cout << "List is Full\n";
            else cout << "List is not Full\n";
            break;
            case 0:
            return 0;
            break;
            default:
            cout << "Please enter a valid choice";
            break;
        }
    } while(true);
}

int Menu() {
    int choice;
    do {
        cout << "\nList of Operations:\n\n";
        cout << "[1] Insert at Beginning\n";
        cout << "[2] Insert at End\n";
        cout << "[3] Insert at Position\n";
        cout << "[4] Remove at Position\n";
        cout << "[5] Search\n";
        cout << "[6] Display List\n";
        cout << "[7] Get Size\n";
        cout << "[8] Check if list is empty\n";
        cout << "[9] Check if list is full\n";
        cout << "[0] Exit\n\n";
        cout << "Enter your choice:\n";
        cout << ":: ";
        cin >> choice;
    } while (choice < 0 || choice > 9);
    return choice;
}

void LinkedList::InputData(int& val) {
    cout << "Enter data: ";
    cin >> val;
}
void LinkedList::InsertAtBeginning(int val) {
    Node* temp;
    if(IsFull()) {
        cout << "Cannot Insert because the list is full";
        return;
    }

    Node* newNode = new Node;
    if (!head) {
        newNode->data = val;
        newNode->next = NULL;
        head = newNode;
    }
    else {
        temp = head;
        newNode->data = val;
        newNode->next = temp;
        head = newNode;
    }

    size = GetSize() + 1;
}

void LinkedList::InsertAtPosition(int val) {
    Node* temp, *newNode, *last;
    int position;

    if(IsFull()) {
        cout << "Cannot Insert because the list is full";
        return;
    }

    cout << "Enter position to insert data: ";
    cin >> position;

    if (position > size) {
        cout << "Invalid Position";
        return;
    } 

    temp = head;
    for (int index = 1; index < position - 1; index++) {
        if (!temp){
            return;
        }
        temp = temp->next;
    }

    newNode = new Node;
    newNode->data = val;
    if(!temp) {
        newNode->next = NULL;
        last = head;
        while (last->next) {
            last = last->next;
        }
        last->next = newNode;
    }
    else {
        newNode->next = temp->next;
        temp->next = newNode;
    }

    size = GetSize() + 1;

}

void LinkedList::InsertAtEnd(int val) {
    Node* temp;

    if(IsFull()) {
        cout << "Cannot Insert because the list is full";
        return;
    }

    Node* newNode = new Node;
    newNode->data = val;
    newNode->next = NULL;

    temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
    size = GetSize() + 1;
}

void LinkedList::RemoveAt() {
    Node* temp1, *temp2;
    int position;
    
    if (IsEmpty()) {
        cout << "The list is empty";
        return;
    }

    temp1 = head;

    cout << "Enter position of element to be deleted: ";
    cin >> position;

    if (position == 1) {
        head = temp1->next;
        delete temp1;
        return;
    }

    for (int index = 1; index < position - 1; index++) {
        temp1 = temp1->next;
    }
    temp2 = temp1->next;
    temp1->next = temp2->next;
    delete temp2;
    size = GetSize() - 1;
    cout << "Element has been deleted";
}

bool LinkedList::Search(int val) {
    Node* temp = head;

    while(temp) {
        if (temp->data == val) {
            return true;
        }
        temp = temp->next;
    }
    return false;
} 

int LinkedList::GetSize() {
    Node *temp = head;
    int count;

    while (temp) {
        temp = temp->next;
        count++;
    }
    return (sizeof(count)*size) / sizeof(int);
}

bool LinkedList::IsEmpty() {
    if (!head)
    return true;
    else 
    return false;
}

bool LinkedList::IsFull() {
    if (GetSize() == 10)
    return true;
    else
    return false;
}

void LinkedList::PrintList() {
    Node *temp;
    int numbering = 1;

    if (IsEmpty()) {
        cout << "The list is currently Empty";
    }
    else {
        temp = head;
        while (temp) {
            cout << "Data #" << numbering << ": " << temp->data << "\n";
            temp = temp->next;
            numbering++;
        }
        cout << "End of list";
    }
}