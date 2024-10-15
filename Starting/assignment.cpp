//Doubly linked list on your preferred system (student, faculty, admin)

//id%4

//0= student

//1= faculty

//2= admin

//3= courseList

//operations: insert, delete, modification, 

 

//c/c++17 minimum preferred

//Header file: macro, enum, menu with callback function, e.g., function pointer
#include <iostream>
#include <conio.h>
using namespace std;
enum UserType
{
    STUDENT = 0,
    FACULTY = 1,
    ADMIN = 2,
    COURSELIST = 3
};
void insert()
{
    cout << "Insertion" << endl;
}
void deletion()
{
    cout << "Deletion" << endl;
}
void modification()
{
    cout << "Modification" << endl;
}
void menu(UserType userType)
{
    switch (userType)
    {
    case STUDENT:
        cout << "Student" << endl;
        break;
    case FACULTY:
        cout << "Faculty" << endl;
        break;
    case ADMIN:
        cout << "Admin" << endl;
        break;
    case COURSELIST:
        cout << "CourseList" << endl;
        break;
    default:
        cout << "Invalid User" << endl;
        break;
    }
}
int main()
{
    int id;
    cout << "Enter the id:";
    cin >> id;
    UserType userType = static_cast<UserType>(id % 4);
    menu(userType);
    switch (userType)
    {
    case STUDENT:
        insert();
        break;
    case FACULTY:
        deletion();
        break;
    case ADMIN:
        modification();
        break;
    case COURSELIST:
        cout << "CourseList" << endl;
        break;
    default:
        cout << "Invalid User" << endl;
        break;
    }
    getch();
}
