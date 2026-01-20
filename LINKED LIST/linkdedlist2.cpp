#include <iostream>
using namespace std;
//DOUBLY LINKED LIST WHOLE TOPIC
class node{
    public:
    int data;
    node* prev;
    node* next;
    node(int d){
        this->data=d;
        this-> prev= NULL;
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
int getlength(node* &head){
    node* temp=head;
    int len=0;
    while(temp!=NULL){
        temp=temp->next;
        len++;
    }
    return len;
}
void insertathead(node* &head,int d){//ISNERTING AT HEAD
    node* temp=new node(d);
    temp->next=head;
    head->prev=temp;
    head=temp;
}
void insertattail(node* &tail,int d){
    node * temp=new node(d);
    tail->next=temp;
    temp->prev=tail;
    tail=temp;
}
void insertatposition(node* &head,node* &tail,int pos,int d){
    if(pos==1){
        insertathead(head,d);
        return;
    }
    int cnt=1;
    node* temp=head;
    node* nodetoinsert=new node(d);
    while(cnt<pos-1){
        temp=temp->next;
        cnt++;
    }
    temp->next->prev=nodetoinsert;
    nodetoinsert->next=temp->next;
    temp->next=nodetoinsert;
    nodetoinsert->prev=temp;
    if(nodetoinsert->next==NULL){
        tail=nodetoinsert;
    }
}
int main(){
    node* node1=new node(19);
    node* head=NULL;
    node* tail=NULL;
    node* node2=new node(20);
    print(head); 
    head->next=node2;
    node2->prev=head;
    tail=node2;
    cout<<"The length of linked list is :"<<getlength(head)<<endl;
    insertathead(head,25);
    print(head);
    insertathead(head,69);
    print(head);
    insertattail(tail,45);
    print(head);
    insertatposition(head,tail,3,1000);
    print(head);
    insertatposition(head,tail,6,69);
    print(head);
    return 0;
}