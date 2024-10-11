#include "faculty.h"

void insert(FacultyNode*& head, int id, const char* name, const char* initial, Designation designation, const char courses[MAX_COURSES][MAX_NAME_LENGTH]) {
    FacultyNode* newNode = new FacultyNode();
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
    std::cout << "Inserted: " << name << " with ID: " << id << std::endl;
}

void deleteNode(FacultyNode*& head, int id) {
    FacultyNode* temp = head;
    while (temp != nullptr && temp->id != id) {
        temp = temp->next;
    }
    if (temp == nullptr) {
        std::cout << "Faculty with ID: " << id << " not found." << std::endl;
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
    std::cout << "Deleted faculty with ID: " << id << std::endl;
}

void modify(FacultyNode*& head, int id, const char* name, const char* initial, Designation designation, const char courses[MAX_COURSES][MAX_NAME_LENGTH]) {
    FacultyNode* temp = head;
    while (temp != nullptr && temp->id != id) {
        temp = temp->next;
    }
    if (temp == nullptr) {
        std::cout << "Faculty with ID: " << id << " not found." << std::endl;
        return;
    }
    strncpy(temp->name, name, MAX_NAME_LENGTH);
    strncpy(temp->initial, initial, MAX_INITIAL_LENGTH);
    temp->designation = designation;
    for (int i = 0; i < MAX_COURSES; ++i) {
        strncpy(temp->courses[i], courses[i], MAX_NAME_LENGTH);
    }
    std::cout << "Modified faculty with ID: " << id << std::endl;
}

void display(FacultyNode* head) {
    FacultyNode* temp = head;
    while (temp != nullptr) {
        std::cout << "ID: " << temp->id << ", Name: " << temp->name << ", Initial: " << temp->initial << ", Designation: " << temp->designation << std::endl;
        for (int i = 0; i < MAX_COURSES; ++i) {
            std::cout << "Course " << i + 1 << ": " << temp->courses[i] << std::endl;
        }
        temp = temp->next;
    }
}

void menu(FacultyNode*& head) {
    int choice;
    do {
        std::cout << "1. Insert\n2. Delete\n3. Modify\n4. Display\n5. Exit\nEnter your choice: ";
        std::cin >> choice;
        switch (choice) {
            case INSERT: {
                int id;
                char name[MAX_NAME_LENGTH];
                char initial[MAX_INITIAL_LENGTH];
                Designation designation;
                char courses[MAX_COURSES][MAX_NAME_LENGTH];

                std::cout << "Enter ID: ";
                std::cin >> id;
                std::cout << "Enter Name: ";
                std::cin.ignore();
                std::cin.getline(name, MAX_NAME_LENGTH);
                std::cout << "Enter Initial: ";
                std::cin.getline(initial, MAX_INITIAL_LENGTH);
                std::cout << "Enter Designation (0: Professor, 1: Associate Professor, 2: Assistant Professor, 3: Lecturer): ";
                int desig;
                std::cin >> desig;
                designation = static_cast<Designation>(desig);
                std::cin.ignore();
                for (int i = 0; i < MAX_COURSES; ++i) {
                    std::cout << "Enter Course " << i + 1 << ": ";
                    std::cin.getline(courses[i], MAX_NAME_LENGTH);
                }

                insert(head, id, name, initial, designation, courses);
                break;
            }
            case DELETE: {
                int id;
                std::cout << "Enter ID to delete: ";
                std::cin >> id;
                deleteNode(head, id);
                break;
            }
            case MODIFY: {
                int id;
                char name[MAX_NAME_LENGTH];
                char initial[MAX_INITIAL_LENGTH];
                Designation designation;
                char courses[MAX_COURSES][MAX_NAME_LENGTH];

                std::cout << "Enter ID to modify: ";
                std::cin >> id;
                std::cout << "Enter Name: ";
                std::cin.ignore();
                std::cin.getline(name, MAX_NAME_LENGTH);
                std::cout << "Enter Initial: ";
                std::cin.getline(initial, MAX_INITIAL_LENGTH);
                std::cout << "Enter Designation (0: Professor, 1: Associate Professor, 2: Assistant Professor, 3: Lecturer): ";
                int desig;
                std::cin >> desig;
                designation = static_cast<Designation>(desig);
                std::cin.ignore();
                for (int i = 0; i < MAX_COURSES; ++i) {
                    std::cout << "Enter Course " << i + 1 << ": ";
                    std::cin.getline(courses[i], MAX_NAME_LENGTH);
                }

                modify(head, id, name, initial, designation, courses);
                break;
            }
            case DISPLAY:
                display(head);
                break;
            case EXIT:
                std::cout << "Exiting..." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != EXIT);
}
int main() {
    FacultyNode* head = nullptr;
    menu(head);
    return 0;
}