#include "faculty.h"

void callbackInsert(FacultyNode*& head, int id, const char* name) {
    insert(head, id, name);
}

void callbackDelete(FacultyNode*& head, int id, const char* name) {
    deletion(head, id);
}

void callbackModify(FacultyNode*& head, int id, const char* name) {
    modification(head, id, name);
}

int main() {
    FacultyNode* head = nullptr;

    UserType userType = STUDENT;
    menu(userType, callbackInsert);

    userType = FACULTY;
    menu(userType, callbackDelete);

    userType = ADMIN;
    menu(userType, callbackModify);

    return 0;
}