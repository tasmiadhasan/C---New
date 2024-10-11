#ifndef FACULTY_H
#define FACULTY_H

#include <iostream>
#include <string>
using namespace std;

// Macros
#define MAX_NAME_LENGTH 100

// Enum for user types
enum UserType {
    STUDENT,
    FACULTY,
    ADMIN,
    COURSELIST
};

// Struct for doubly linked list node
struct FacultyNode {
    int id;
    char name[MAX_NAME_LENGTH];
    FacultyNode* prev;
    FacultyNode* next;
};

// Function prototypes
void insertFaculty(FacultyNode** head, int id, const char* name);
void deleteFaculty(FacultyNode** head, int id);
void modifyFaculty(FacultyNode* head, int id, const char* newName);

// Menu function with callback
typedef void (*MenuCallback)(FacultyNode** head);

void menu(FacultyNode** head, MenuCallback insertCb, MenuCallback deleteCb, MenuCallback modifyCb);

#endif // FACULTY_H