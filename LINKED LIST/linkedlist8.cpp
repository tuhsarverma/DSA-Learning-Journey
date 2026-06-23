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
};
void print(node* &head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
void insertathead(node* &head,int d){// INSERTATHEAD
    if(head==NULL){
        node* temp=new node(d);
        head=temp;
    }
    else{
        node* temp=new node(d);
    temp->next=head;
    head=temp;
    }
}
node* getmiddle(node* head){
    node* slow=head;
    node* fast=head->next;
    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}
bool ispalindrome(node* head){
    node* temp=head;
    int cnt=0;
    while(temp!=NULL){
        temp=temp->next;
        cnt++;
    }
    temp=head;
    int arr[cnt]={0};
    int i=0;
    while(temp!=NULL){
        arr[i]=temp->data;
        i++;
        temp=temp->next;
    }
    int s=0;
    int e=cnt-1;
    while(s<=e){
        if(arr[s++]!=arr[e--]){
            return false;
        }
    }
    return true;
}
node* reverse(node*  head){
    node* curr=head;
    node* prev=NULL;
    node* next=NULL;
    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}
bool ispalindrome1(node* head){
    if(head==NULL || head->next==NULL){
        return true;
    }
    node* middle=getmiddle(head);
    node* temp=middle->next;
    node* head1=head;
    node* head2 =middle->next;
    while(head2!=NULL){
        if(head1->data!=head2->data){
            return false;
        }
        head1=head1->next;
        head2=head2->next;
    }



}