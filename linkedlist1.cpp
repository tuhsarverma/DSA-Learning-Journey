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
void insertathead(node* &head,int D){
    node* node1=new node(D);
    node* temp=node1;
    head=temp;
}
void print(node* &head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<endl;
        temp=temp->next;
    }
}
int main (){
    int P=12;
    node* node1=new node(P);
    cout<<node1->data<<endl;
    cout<<node1->next;

    return 0;
}