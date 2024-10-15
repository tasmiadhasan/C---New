#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};
void insertatHead(node* &head,int new_data){
    node* temp=new node(new_data);
    temp->

};

int main(){
    node* node1=new node(10);
    cout<<node1->data<<endl;
    cout<<node1->next<<endl;
}