#ifndef FACULTY_H
#define FACULTY_H

#include <iostream>
#include <cstring>

#define MAX_NAME_LENGTH 100
#define MAX_INITIAL_LENGTH 10
#define MAX_COURSES 5

enum Designation {
    PROFESSOR,
    ASSOCIATE_PROFESSOR,
    ASSISTANT_PROFESSOR,
    LECTURER
};

enum MenuOption {
    INSERT = 1,
    DELETE,
    MODIFY,
    DISPLAY,
    EXIT
};

struct FacultyNode {
    int id;
    char name[MAX_NAME_LENGTH];
    char initial[MAX_INITIAL_LENGTH];
    Designation designation;
    char courses[MAX_COURSES][MAX_NAME_LENGTH];
    FacultyNode* prev;
    FacultyNode* next;
};

void insert(FacultyNode*& head, int id, const char* name, const char* initial, Designation designation, const char courses[MAX_COURSES][MAX_NAME_LENGTH]);
void deleteNode(FacultyNode*& head, int id);
void modify(FacultyNode*& head, int id, const char* name, const char* initial, Designation designation, const char courses[MAX_COURSES][MAX_NAME_LENGTH]);
void display(FacultyNode* head);
void menu(FacultyNode*& head);

#endif // FACULTY_H