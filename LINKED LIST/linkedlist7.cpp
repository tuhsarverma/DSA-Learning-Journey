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
int count(node* head,int data){
    int cnt=0;
    node* temp=head;
    while(temp!=NULL){
        if(temp->data==data){
            cnt++;
        }
        temp=temp->next;
    }
    return cnt;
}
node* sortthenode(node* &head){
    node* temp=head;
    int cnt0=count(head,0);
    int cnt1=count(head,1);
      int cnt2=count(head,2);
    while(cnt0>0){
        temp->data=0;
        temp=temp->next;
        cnt0--;
    }
      while(cnt1>0){
        temp->data=1;
        temp=temp->next;
        cnt1--;
        }

      while(cnt2>0){
        temp->data=2;
        temp=temp->next;
        cnt2--;
    }
    return head;
}
void print(node* &head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
void populate(node* &tail,node* curr){
    tail->next=curr;
    tail=curr;
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
// SECOND METH0D- MAKE 3 NODES AND THEN MERGE THEM ALL  TO FORM THE RESULT
node* second2method(node*head){
    node* zerohead=new node(-1);
    node* zerotail=zerohead;
    node* onehead=new node(-1);
    node* onetail=onehead;
    node* twohead=new node(-1);
    node* twotail=twohead;
    node* curr=head;
    while(curr!=NULL){
        int value=curr->data;
        if(value==0){
            populate(zerotail,curr);
        }
        else if (value==0){
            populate(onetail,curr);
        }
        else if(value==0){
            populate(twotail,curr);
        }
        curr=curr->next;
    }
    if(onehead->next!=NULL){
        zerotail->next=onehead->next;
    }
    else{
        zerotail->next=twohead->next;
    }
    onetail->next=twohead->next;
    twotail->next=NULL;
    head=zerohead->next;
    delete zerohead;
    delete onehead;
    delete twohead;
    return head;
}
// MERGE TWO SORTED  LINKED LIST
node* merge2sorted(node* head1,node* head2){
    node* temp1=head1;
    node* temp2=head2;
    node* currhead=new node(-1);
    node* currtail=currhead;
    while(temp1!=NULL&&temp2!=NULL){
        if(temp1->data>temp2->data){
            currtail->next=temp2;
            temp2=temp2->next;
        }
        else{
            currtail->next=temp1;
            temp1=temp1->next;
        }
        currtail=currtail->next;
    }
    if(temp1!=NULL){ currtail->next = temp1;
     }
     if(temp2!=NULL){ currtail->next = temp2;
     }
    node* head=currhead->next;
    return head;
}
node* solve(node* &head1,node* &head2){
    if(head1->next==NULL){
        head1->next=head2;
    }
    node* curr1=head1;
    node* curr2=head2;
    node* next1=curr1->next;
    node* next2=curr2->next;
    while(next1!=NULL&&curr2!=NULL){
        if((curr2->data>curr1->data)&&(curr2->data<=next1->data)){
            curr1->next=curr2;
            next2=curr2->next;
            curr2->next=next1;
            curr1=curr2;
            curr2=next2;
        }
        else{
            curr1=next1;
            next1=next1->next;
            if(next1==NULL){
                curr1->next=curr2;
                return head1;
            }
        }
    }
    return head1;
}
node* merger2_sorted(node* first,node* second){
    if( first==NULL){
        return second;
    }
    if(second==NULL){
        return first;
    }
    if(first->data<=second->data){
        solve(first,second);
    }
    else{
        solve(second,first);
    }
}


int main(){
    node* head=NULL;
     insertathead(head,2);
    insertathead(head,2);
    insertathead(head,0);
    insertathead(head,1);
    insertathead(head,1);
    sortthenode(head);
    print(head);
    return 0;
}