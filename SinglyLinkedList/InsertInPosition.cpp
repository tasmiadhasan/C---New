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
void print(node* &head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
void insertinPosition(node* & head,int position,int data){
    node* temp =head;
   int n=1;
   while(n<position-1){
    temp=temp->next;
    n++;
   } 
   node* insert =new node(data);
   insert->next=temp->next;
   temp->next=insert;
}
int main(){
    node* node1=new node(10);
    node* head=node1;
    insertinPosition(head,2,11);
    print(head);
}