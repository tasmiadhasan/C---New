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
void insertatTail(node* & tail,int data){
    node* temp=new node(data);
    tail->next=temp;
    tail=tail->next;
}
void print(node* &head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main(){
    node* node1=new node(14);
    node* head=node1;
    node* tail=node1;
    insertatTail(tail,15);
    print(head);
}

