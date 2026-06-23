#include <iostream>
using namespace std; 
class node{
    public:
    int data;
    node*  next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};
void insert(node* &head,int d){
    node* temp=new node(d);
    if(head==NULL){
        head=temp;
        return;
    }
    temp->next=head;
    head=temp;
}
void print(node* head){

    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
// SORTED LINKED LIST  TC-O(N)  SC-O(1)
node* removeduplicate(node* head){
    if(head==NULL||head->next==NULL){
        return  head;
    }
    node* prev=head;
    node* curr=head->next;
    while(curr!=NULL){
        if(curr->data==prev->data){
            node* temp=curr;
            prev->next=temp->next;
            curr=curr->next;
            temp->next=NULL;
        }
        else{
            prev=prev->next;
            curr=curr->next;
        }
    }
    return head;
}
// REMOVE DUPLICATE FROM UNSORTED LINKED LIST

node* removeduplicatesfromunsorted(node* head){
    node* temp=head;
    if(head==NULL||head->next==NULL){
        return head;
    }
    while(temp->next!=NULL){
        node* temp1=temp;
        node* temp2=temp->next;
        while(temp2!=NULL){
            if(temp2->data==temp->data){
                node* curr=temp2;
                temp1->next=temp2->next;
                temp2=temp2->next;
                curr->next=NULL;
            }
            else{
                temp1=temp1->next;
                temp2=temp2->next;
            }
        }
        temp=temp->next;
    }
    return head;
}
/*node* method2toremoveunsorted(node* head){
    //SORT THE LINKED LIST
    node* temp=head;
    while(temp->next=NULL){
        node* next=temp->next;
        while(next!=NULL){
            if(next->data==temp->data){
                if(temp==head){
                    node* newone=next;
                    head->next=next->next;
                    next->next=head;
                    head=next;
                }
                else{
                    node* newone=next;
                    temp->next=next->next;
                    newone->next=temp;
                }
            }
            else{
                next=next->next;
            }
        }
        temp=temp->next;sss
    }
}*/
int main(){
    node* head=NULL;
    insert(head,7);
    print(head);
    insert(head,5);
    insert(head,5);
    insert(head,6);
    insert(head,6);
    insert(head,6);
    insert(head,6);
    print(head);
    cout<<head;
    method2toremoveunsorted(head);
    print(head);
    return 0;
}