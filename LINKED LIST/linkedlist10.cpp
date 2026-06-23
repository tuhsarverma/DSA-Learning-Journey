#include <iostream>
#include <unordered_map>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node* random;
    node(int data){
        this->data=data;
        this->next=NULL;
        this->random=NULL;
    }
};
void insertattail(node*& head,node* &tail,int data){
    node* temp=new node(data);
    if(head==NULL){
        head=temp;
        tail=temp;
        return;
    }
    else{
        tail->next=temp;
        tail=temp;
    }
    
}
//USING MAP
node* copylist(node* head){
    //CREATE A CLONE LIST
    node* clonehead=NULL;
    node* clonetail=NULL;
    node* temp=head;
    while(temp!=NULL){
        insertattail(clonehead,clonetail,temp->data);
        temp=temp->next;
    }
    //CREATE A MAP
    unordered_map<node* , node*>oldtonew;
    node* originalnode=head;
    node* clonenode=clonehead;
    
        while(originalnode!=NULL&&clonenode!=NULL){
            oldtonew[originalnode]=clonenode;
            originalnode=originalnode->next;
            clonenode=clonenode->next;
        }
        originalnode=head,clonenode=clonehead;
        while(originalnode!=NULL){
            clonenode->random=oldtonew[originalnode->random];
            originalnode=originalnode->next;
            clonenode=clonenode->next;
        }
        return clonehead;
}
///  WITHOUT MAPS(LESS SPACE)!!!  ///
node* copylist_1(node* head){
    // CREATE A CLONE NODE
    node* clonehead=NULL;
    node* clonetail=NULL;
    node* temp=head;
    while(temp!=NULL){
        insertattail(clonehead,clonetail,temp->data);
        temp=temp->next;
    }
    // STEP2: CLONE NODES ADD IN BTW ORIGINAL NODES
    node* originalnode=head;
    node* clonenode=clonehead;
    while(originalnode!=NULL&&clonenode!=NULL){
        node* next=originalnode->next;
        originalnode->next=clonenode;
        originalnode=next;
        next=clonenode->next;
        clonenode->next=originalnode;
        clonenode= next;
    }
    // STEP3: RANDOM POINTER COPY
    temp=head;
    while(temp!=NULL){
        if(temp->next!=NULL){
            if(temp->random!=NULL){
                temp->next->random=temp->random->next; 
            }
            else{
                temp->next=temp->random;
            }
        }
       
    }
    originalnode=head;
    clonenode=clonehead;
     while(originalnode!=NULL&&clonenode!=NULL){
        originalnode->next=clonenode->next;
        originalnode=originalnode->next;
        if(originalnode!=NULL){
            clonenode->next=originalnode->next;
        }
        clonenode=clonenode->next;
    }
    return clonehead;

}


int main(){
    return 0;
}