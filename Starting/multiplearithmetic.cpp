#include<iostream>
#include<conio.h>
using namespace std;
int main(){
    int a;
    int b;
    cout<<"Enter the first value:";
    cin>>a;
    cout<<"Enter the second value:";
    cin>>b;
    int sum=a+b;
    int minus=a-b;
    float mul=a*b;
    double div=(float)a/(float)b;
    double mod=a%b;
    cout<<"The sum of the two values is:"<<sum<<endl;
    cout<<"The difference of the two values is:"<<minus<<endl;
    cout<<"The product of the two values is:"<<mul<<endl;
    cout<<"The division of the two values is:"<<div<<endl;
    cout<<"The modulus of the two values is:"<<mod<<endl;
    getch();
}