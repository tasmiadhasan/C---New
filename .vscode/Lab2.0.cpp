#include<iostream>
#include<conio.h>
using namespace std;
int main(){
int *ptr; 
ptr = new int; 
cin >> *ptr; 
cout << *ptr << endl; 
delete ptr; 
ptr = NULL;
cout<<ptr;
cin>>*ptr;
cout<<*ptr;
}