#include <iostream>
using namespace std;

struct Record;

class Student {
    public:
    Student();
    virtual ~Student();
    
    void Format(){
    cout << "Name: " << GetFirstName() << " " << GetMiddleName() << " " << GetLastName() << "\n";
    cout << "Year Level: " << GetYearLevel() << "\n";
    cout << "Course: " << GetCourse() << "\n";
    }
    void Display() {
        this->Format(); cout << "\n\n";
    }
    void SetLastName() {
        cout << "Enter Last Name: ";
        cin >> lastName;
    }
    void SetFirstName(){
        cout << "Enter First Name: ";
        cin >> firstName;
    }
    void SetMiddleName(){
        cout << "Enter Middle Name: ";
        cin >> middleName;
    }
    void SetYearLevel() {
        cout << "Enter Year Level: ";
        cin >> yearLevel;
    }
    void SetCourse() {
        cout << "Enter Course: ";
        cin >> course;
    }
    string GetLastName() {
        return lastName;
    }
    string GetFirstName() {
        return firstName;
    }
    string GetMiddleName() {
        return middleName;
    }
    int GetYearLevel() {
        return yearLevel;
    }
    string GetCourse() {
        return course;
    }
    void AddStudentData(Student&);
    void AddStudentRecord(Record*&, Record*&, Student&);
    void SearchStudent(Record*&);
    void ShowAllStudent(Record*&);
    void RemoveAStudent(Record*&);
    void RemoveAllStudent(Record*&);

    private:
       string firstName;
       string lastName;
       string middleName;
       string course;
       int yearLevel;
};
struct Record {
    Student* student;
    Record *next = NULL;
    Record *prev = NULL;

};

int MainMenu();

int main() {
    Student st;
    Student tempStudentHolder;
    Record *head = NULL, * tail = NULL;

    do {
        switch(MainMenu()) {
            case 1:
                st.AddStudentData(tempStudentHolder);
                st.AddStudentRecord(head, tail, tempStudentHolder);
                break;
            case 2:
                st.ShowAllStudent(head);
                break;
            case 3:
                st.SearchStudent(head);
                break;
            case 4:
                st.RemoveAStudent(head);
                break;
            case 5:
                st.RemoveAllStudent(head);
                break;
            case 6:
            exit(0);
                break;
            default:
                cout << "Invalid Input" << endl;
                break;
        }
    }while (true);

}

Student::Student(){
    cout << "Student is being constructed\n";
}

Student::~Student(){
    cout << "Student is being destructed\n\n";
}

int MainMenu() {
    int choice;
    do {
    cout << "[1] Add Student\n";
    cout << "[2] Show All Students\n";
    cout << "[3] Search For Student\n";
    cout << "[4] Delete A Student Record\n";
    cout << "[5] Delete All Student Record\n";
    cout << "[6] Exit\n\n";
    cout << ":: ";
    cin >> choice;
    } while (choice < 0 || choice > 6);
    return choice;
}

void Student::AddStudentData(Student& tempStudentHolder) {
    tempStudentHolder.SetFirstName();
    tempStudentHolder.SetMiddleName();
    tempStudentHolder.SetLastName();
    tempStudentHolder.SetYearLevel();
    tempStudentHolder.SetCourse();
}

void Student::AddStudentRecord(Record*& head, Record*& tail, Student& tempStudentHolder) {
    Record* temp = new Record;
    temp->student = new Student(tempStudentHolder);
    temp->next = NULL;

    if (!head) 
        head = temp;
    else
        tail->next = temp;

    tail = temp;
}

void Student::ShowAllStudent(Record*& head) {
    Record* temp = head;

    if (!head)
        cout << "-- No Record Yet --";
    else {
        while (temp) {
            temp->student->Display();
            temp = temp->next;
        }
    }
}

void Student::SearchStudent(Record*& head) {
    string searchLastName;
    bool found = false;
    Record* temp = head;

    cout << "Enter the last name of the student you want to search for: ";
    cin >> searchLastName;


    while (temp) {
        if (temp->student->GetLastName() == searchLastName) {
            temp->student->Display();
            found = true;
        }
        temp = temp->next;
    }

    if (!found) {
        cout << "No such student in the record" << endl;
    }
}

void Student::RemoveAStudent(Record*& head) {
    string searchLastName;
    Record* temp = head;
    Record* prev = NULL;
    cout << "Enter the last name of the student you want to remove: ";
    cin >> searchLastName;
    
    bool found = false;

    while (temp) {
        if (temp->student->GetLastName() == searchLastName) {
            found = true;
            if (temp == head) {
                head = temp->next;
                delete temp->student;
                delete temp;
                cout << "Student removed successfully." << endl;
                return;
            } else {
                prev->next = temp->next;
                delete temp->student;
                delete temp;
                cout << "Student removed successfully." << endl;
                return;
            }
        }
        prev = temp;
        temp = temp->next;
    }

    if (!found) {
        cout << "No student with the given last name found." << endl;
    }
}

void Student::RemoveAllStudent(Record*& head) {
    Record* temp;
    while (head) {
        temp = head;
        head = head->next;
        delete temp->student; 
        delete temp;          
    }
    cout << "Successfully cleared records" << endl;
}
