#include <iostream>
using namespace std;
class node{
    public:
    
    int data;
    node* next;
    node(int D){
        this->data=D;
        this->next=NULL;
    }
};
void insertattail(node* &tail,int D){
    node* temp=new node(D);
    tail->next=temp;
    tail=tail->next;
    
}
void print(node* &head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
int main (){
    int P=12;
    node* node1=new node(P);
    cout<<node1->data<<endl;
    node* head=node1;
    node* tail=node1;
    insertattail(tail,10);
    print(head);

    return 0;
}