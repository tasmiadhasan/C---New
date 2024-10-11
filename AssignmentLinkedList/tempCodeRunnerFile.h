#ifndef FACULTY_H
#define FACULTY_H

#include <iostream>
#include <string>
using namespace std;
#define MAX_NAME_LENGTH 100
#define MAX_INITIAL_LENGTH 10
#define MAX_COURSE_LIST_LENGTH 10


// Enum for faculty designations
enum FacultyDesignation {
    PROFESSOR,
    ASSOCIATE_PROFESSOR,
    ASSISTANT_PROFESSOR,
    LECTURER
};

// Enum for menu options
enum MenuOption {
    INSERT_FACULTY = 1,
    DELETE_FACULTY,
    MODIFY_FACULTY,
    EXIT
};

// Struct for doubly linked list node
struct FacultyNode {
    int id;
    char name[MAX_NAME_LENGTH];
    char initial[MAX_INITIAL_LENGTH];
    string courseList[MAX_COURSE_LIST_LENGTH];
    FacultyDesignation designation;
    FacultyNode* prev;
    FacultyNode* next;
};

// Function pointer type for menu callbacks
typedef void (*MenuCallback)();

// Function declarations
void insertFaculty(FacultyNode** head, int id, const char* name, const char* initial, string courseList[], FacultyDesignation designation);
void deleteFaculty(FacultyNode** head, int id);
void modifyFaculty(FacultyNode* head, int id, const char* name, const char* initial, string courseList[], FacultyDesignation designation);

// Menu function
void displayMenu(MenuCallback insertCallback, MenuCallback deleteCallback, MenuCallback modifyCallback);

#endif // FACULTY_H