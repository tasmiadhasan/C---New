#include<iostream>
#include<conio.h>
using namespace std;
int main(){
    int size;
    cout<<"Enter array size:";
    cin>>size;
    int *array;
    array=new int [size];
    for(int i=0;i<size;i++){
        cin>>array[i];
    }
    for(int j=0;j<size;j++){
        cout<<array[j]<<endl;
    }
    delete []array;
    cout<<"This is the array"<<endl;
    for(int k=0;k<size;k++){
        cout<<array[k]<<endl;
    }
}