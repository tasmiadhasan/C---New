#include<iostream>
#include<conio.h>
using namespace std;
class Employee{
    public:
    string name;
    int ID;
    double salary;
    void printinfo(){
        cout<<"Name: "<<name<<endl;
        cout<<"ID: "<<ID<<endl;
        cout<<"Salary: "<<salary<<endl;
    }

};
int main(){
    Employee e1;
    e1.name="John Doe";
    e1.ID=123456;
    e1.salary=50000;
    e1.printinfo();
    Employee e2;
    e2.name="Jane Doe";
    e2.ID=654321;
    e2.salary=60000;
    e2.printinfo();

}