#include<iostream>
#include<conio.h>
using namespace std;

class TestClass{
    public:
    int custnum;
    double custdec;
    
    void testmethod(){
        cout<<"This is a test method."<<"\n"<<endl;

      }
};

void isEven(int n){
    if(n%2==0 && n!=0){
        cout<<" The number "<<n<<" is even "<<endl;
    }
    if(n==0){
        cout<<" The number "<<n<<" is a zero "<<endl;
    }
    else{
        cout<<" The number "<<n<<" is odd "<<endl;
    }
}

int main(){
    TestClass test;
    test.custnum=32;
    test.custdec=3.14;
    cout<<"The value for custnum : "<<test.custnum<<endl;
    cout<<"The value for custdec : "<<test.custdec<<endl;
    test.testmethod();
    cout<<"Enter a integer number:";
    int n;
    cin>>n;
    isEven(n);


}
