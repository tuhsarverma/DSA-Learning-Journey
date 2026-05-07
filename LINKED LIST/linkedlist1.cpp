#include <iostream>
using namespace std;
//SINGLY LINKED LIST WHOLE TOPIC
class node{
    public:
    
    int data;
    node* next;
    node(int D){
        this->data=D;
        this->next=NULL;
    }
    ~node(){
        int value=this->data;
        if(this->next!=NULL){
            delete next;
            this->next=NULL;
        }
        cout<<" memory is free for node with  "<<value<< "  ";
    }
};
void insertathead(node* &head,int d){// INSERTATHEAD
    node* temp=new node(d);
    temp->next=head;
    head=temp;
}
void insertattail(node* &tail,int d){//INSERTATTIAL
    node* temp=new node(d);
    tail->next=temp;
    tail=temp;
    tail->next=NULL;
}
void insertatposition(node* &tail,node* &head,int pos,int d){
    if(pos==1){
        insertathead(head,d);// IF POS IS 1
        return;
    }
    int cnt=1;
    node* temp=head;
    while(cnt<pos-1){
        temp=temp->next;
        cnt++;
    }
    if(temp->next==NULL){
        insertattail(tail,d);
        return;
    }
    node* nodetoinsert=new node(d);
    nodetoinsert->next=temp->next;
    temp->next=nodetoinsert;
}
void print(node* &head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    } 
    cout<<endl;
}
void deleteatposition(node* &tail,int pos,node* &head){
    if(pos==1){
        node* temp=head;
        head=temp->next;
        temp->next=NULL;
        delete temp;
        
    }
    else{
        node* prev=NULL;
        node* curr=head;
        int cnt=1;
        while(cnt<pos){
            cnt++;
            prev=curr;
            curr=curr->next;
        }
        prev->next=curr->next;
        curr->next=NULL;  
        delete curr;     

    }
}
int main (){
    int P=12;
    node* node1=new node(P);
    cout<<node1->data<<endl;
    node* head=node1;
    node* tail=node1;
    insertattail(tail,98);
    insertathead(head,18);
    insertattail(tail,999);
    print(head);
    insertatposition(tail,head,3,5655);
    print(head);
    insertatposition(tail,head,1,99);
    print(head);
    cout<<"HEAD ="<<head->data<<endl;
    cout<<"TAIL ="<<tail->data<<endl;
    cout<<"AFTER DELETION"<<endl;
    deleteatposition(tail,4,head);
    print(head);
    deleteatposition(tail,4,head);
    print(head);
     deleteatposition(tail,5,head);
    print(head);
    return 0;
}