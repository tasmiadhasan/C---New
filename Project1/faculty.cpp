#include <iostream>
#include "faculty.h"
using namespace std;

const char* getDesignationString(Designation designation) {
    switch (designation) {
        case PROFESSOR: return "PROFESSOR";
        case ASSOCIATE_PROFESSOR: return "ASSOCIATE_PROFESSOR";
        case ASSISTANT_PROFESSOR: return "ASSISTANT_PROFESSOR";
        case LECTURER: return "LECTURER";
        default: return "UNKNOWN";
    }
}

void insert(FacultyNode*& head, int id, const char* name, const char* initial, Designation designation, const char courses[MAX_COURSES][MAX_NAME_LENGTH]) {
    FacultyNode* newNode = new FacultyNode;
    newNode->id = id;
    strncpy(newNode->name, name, MAX_NAME_LENGTH);
    strncpy(newNode->initial, initial, MAX_INITIAL_LENGTH);
    newNode->designation = designation;
    for (int i = 0; i < MAX_COURSES; ++i) {
        strncpy(newNode->courses[i], courses[i], MAX_NAME_LENGTH);
    }
    newNode->prev = nullptr;
    newNode->next = head;
    if (head != nullptr) {
        head->prev = newNode;
    }
    head = newNode;
}

void deleteNode(FacultyNode*& head, int id) {
    FacultyNode* temp = head;
    while (temp != nullptr && temp->id != id) {
        temp = temp->next;
    }
    if (temp == nullptr) return; // Node not found
    if (temp->prev != nullptr) {
        temp->prev->next = temp->next;
    } else {
        head = temp->next;
    }
    if (temp->next != nullptr) {
        temp->next->prev = temp->prev;
    }
    delete temp;
}

void modify(FacultyNode*& head, int id, const char* name, const char* initial, Designation designation, const char courses[MAX_COURSES][MAX_NAME_LENGTH]) {
    FacultyNode* temp = head;
    while (temp != nullptr && temp->id != id) {
        temp = temp->next;
    }
    if (temp == nullptr) return; // Node not found
    strncpy(temp->name, name, MAX_NAME_LENGTH);
    strncpy(temp->initial, initial, MAX_INITIAL_LENGTH);
    temp->designation = designation;
    for (int i = 0; i < MAX_COURSES; ++i) {
        strncpy(temp->courses[i], courses[i], MAX_NAME_LENGTH);
    }
}

void display(FacultyNode* head) {
    FacultyNode* temp = head;
    while (temp != nullptr) {
        cout << "Faculty ID: " << temp->id << "\n";
        cout << "Faculty Name: " << temp->name << "\n";
        cout << "Faculty Initial: " << temp->initial << "\n";
        cout << "Faculty Designation: " << getDesignationString(temp->designation) << "\n";
        cout << "Taking Courses: ";
        for (int i = 0; i < MAX_COURSES; ++i) {
            cout << temp->courses[i] << " ";
        }
        cout << "\n\n";
        temp = temp->next;
    }
}

void menu(FacultyNode*& head) {
    int choice, id;
    char name[MAX_NAME_LENGTH], initial[MAX_INITIAL_LENGTH];
    Designation designation;
    char courses[MAX_COURSES][MAX_NAME_LENGTH];

    while (true) {
        cout << "1. Insert Faculty Details\n2. Delete Faculty\n3. Modify Faculty INFO\n4. Display Faculty Information\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cout<<endl;

        switch (choice) {
            case INSERT:
                cout << "Faculty ID: ";
                cin >> id;
                cout << "Faculty Name: ";
                cin.ignore();
                cin.getline(name, MAX_NAME_LENGTH);
                cout << "Faculty Initial: ";
                cin.getline(initial, MAX_INITIAL_LENGTH);
                cout << "Faculty Designation (0: PROFESSOR, 1: ASSOCIATE_PROFESSOR, 2: ASSISTANT_PROFESSOR, 3: LECTURER): ";
                int desig;
                cin >> desig;
                designation = static_cast<Designation>(desig);
                cin.ignore();
                for (int i = 0; i < MAX_COURSES; ++i) {
                    cout << "Enter Course " << i + 1 << ": ";
                    cin.getline(courses[i], MAX_NAME_LENGTH);
                }
                insert(head, id, name, initial, designation, courses);
                cout << "Faculty Information Updated Successfully!" << endl;
                break;
            case DELETE:
                cout << "Enter Faculty ID to delete: ";
                cin >> id;
                deleteNode(head, id);
                cout << "Faculty Deleted Successfully." << endl;
                break;
            case MODIFY:
                cout << "Enter Faculty ID to modify: ";
                cin >> id;
                cout << "Enter Faculty Name: ";
                cin.ignore();
                cin.getline(name, MAX_NAME_LENGTH);
                cout << "Enter Faculty Initial: ";
                cin.getline(initial, MAX_INITIAL_LENGTH);
                cout << "Enter Faculty Designation (0: PROFESSOR, 1: ASSOCIATE_PROFESSOR, 2: ASSISTANT_PROFESSOR, 3: LECTURER): ";
                cin >> desig;
                designation = static_cast<Designation>(desig);
                cin.ignore();
                for (int i = 0; i < MAX_COURSES; ++i) {
                    cout << "Enter Course " << i + 1 << ": ";
                    cin.getline(courses[i], MAX_NAME_LENGTH);
                }
                modify(head, id, name, initial, designation, courses);
                cout << "Faculty INFO modified Successfully" << endl;
                break;
            case DISPLAY:
                display(head);
                break;
            case EXIT:
                return;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}

int main() {
    FacultyNode* head = nullptr;
    menu(head);
    return 0;
}