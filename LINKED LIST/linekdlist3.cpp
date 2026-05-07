#include <iostream>
using namespace std;
class node{
    int data;
    node* next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
    ~node(){
        int value=this->data;
        if(this->next!=NULL){
            delete next;
            next=NULL;
        }
        cout<<" the memory is free for value"<<value<<endl;
    }
};
void insertatnode(node* tail,int element,int d){
    if(tail==NULL){
        node* newnode=new node(d);
        tail=newnode;
        newnode->next=newnode;
    }
    else{
        node* curr=tail;
        while(curr->data!=element){
            curr=curr->next;
        }
        
    }

}

int main(){

}