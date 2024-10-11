#include "faculty.h"
#include <iostream>
#include <cstring>

using namespace std;

// Function to insert a new faculty node
void insert(FacultyNode*& head, int id, const char* name) {
    FacultyNode* newNode = new FacultyNode();
    newNode->id = id;
    strncpy(newNode->name, name, MAX_NAME_LENGTH);
    newNode->prev = nullptr;
    newNode->next = head;

    if (head != nullptr) {e
        head->prev = newNode;
    }
    head = newNode;
    cout << "Inserted: " << name << " with ID: " << id << endl;
}

// Function to delete a faculty node by id
void deletion(FacultyNode*& head, int id) {
    FacultyNode* temp = head;

    while (temp != nullptr && temp->id != id) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Faculty with ID: " << id << " not found." << endl;
        return;
    }

    if (temp->prev != nullptr) {
        temp->prev->next = temp->next;
    } else {
        head = temp->next;
    }

    if (temp->next != nullptr) {
        temp->next->prev = temp->prev;
    }

    delete temp;
    cout << "Deleted faculty with ID: " << id << endl;
}

// Function to modify a faculty node's name by id
void modification(FacultyNode* head, int id, const char* newName) {
    FacultyNode* temp = head;

    while (temp != nullptr && temp->id != id) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Faculty with ID: " << id << " not found." << endl;
        return;
    }

    strncpy(temp->name, newName, MAX_NAME_LENGTH);
    cout << "Modified faculty with ID: " << id << " to new name: " << newName << endl;
}

// Menu function with callback
void menu(UserType userType, void (*callback)(FacultyNode*& head, int id, const char* name)) {
    FacultyNode* head = nullptr;
    int choice, id;
    char name[MAX_NAME_LENGTH];

    while (true) {
        cout << "Menu:\n1. Insert\n2. Delete\n3. Modify\n4. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter ID: ";
                cin >> id;
                cout << "Enter Name: ";
                cin.ignore();
                cin.getline(name, MAX_NAME_LENGTH);
                callback(head, id, name);
                break;
            case 2:
                cout << "Enter ID to delete: ";
                cin >> id;
                deletion(head, id);
                break;
            case 3:
                cout << "Enter ID to modify: ";
                cin >> id;
                cout << "Enter new Name: ";
                cin.ignore();
                cin.getline(name, MAX_NAME_LENGTH);
                modification(head, id, name);
                break;
            case 4:
                return;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}

int main() {
    menu(FACULTY, insert);
    return 0;
}