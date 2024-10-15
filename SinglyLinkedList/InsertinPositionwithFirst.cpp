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
    cout<<endl;
}
void insertinHead(node* &head,int data){
    node* temp=new node(data);
    temp->next=head;
    head=temp;
}
void insertinPosition(node* &head,int position,int data){
    if(position==1){
        insertinHead(head,data);
    }
    else{
    node* temp=head;
    int n=1;
    while(n<position-1){
        temp=temp->next;
        n++;
    }
    node* insert=new node(data);
    insert->next=temp->next;
    temp->next=insert;
    }
}
int main(){
    node* node1=new node(45);
    node* head=node1;
    insertinPosition(head,1,46);
    print(head);
}
