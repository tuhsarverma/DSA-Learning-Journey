#include <iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int d){
        this->data=d;
        this->next=NULL;
    }
    ~node(){
        cout<<" the memory is free with the data"<<data<<endl;
    }
};
void insertatnode(node* &tail,int element,int d){
    node* temp=new node(d);
    if(tail== NULL){
        tail=temp;
        temp-> next=temp;
        return ;
    }
    node* curr=tail;
    do{
        if(curr->data==element) break;
        curr= curr-> next;
    }while( curr!=tail);
    temp->next=curr->next;
    curr->next=temp;
}
void print(node* &tail){
    if(tail==NULL){
        cout<<" LIST ME KCH NI HAI ";
        return ;
    }
    node* temp=tail;
    do{
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    while(temp!=tail);
    cout<<endl;
}
void deleteatnode(node* &tail,int d){
    if(tail==NULL){
        cout<<"AGAIN WATCH THE LINKED LIST";
        return ;
    }
    else{
        node* prev=tail;
        node* curr=tail->next;
        while(curr->data!=d){
            prev=curr;
            curr=curr->next;
        }
        prev->next=curr->next;
        if(curr==prev){
            tail=NULL;
        }
        else if(tail==curr){
            tail=prev;
        }
        curr->next=NULL;
        delete curr;
    }
}
int main(){
    node* tail=NULL;
    insertatnode(tail,4,3);
    print(tail);
    insertatnode(tail,3,4);
    print(tail);
     insertatnode(tail,3,6);
    print(tail);
    deleteatnode(tail,3);
    print(tail);
        deleteatnode(tail,4);
    print(tail);
        deleteatnode(tail,6);
    print(tail);
}