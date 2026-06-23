#include <iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};
node* reverse(node* head){
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
void print(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
node* insertatnode(node* &head,int data){
    node* temp=new node(data);
    if(head==NULL){
        head=temp;
    }
    else{
        temp->next=head;
        head=temp;
    }
}
int solveadd(node* head1,node* head2){
    node* temp1=head1;
    node* temp2=head2;
    int cnt1=0,cnt2=0;
    while(temp1!=NULL){
        cnt1=cnt1*10+temp1->data;
        temp1=temp1->next;
    }
     while(temp2!=NULL){
        cnt2=cnt2*10+temp2->data;
        temp2=temp2->next;
    }
    int sum=cnt2+cnt1;
    return sum;
}

//2nd method to return added ans in node form
void insertattail(node* &head,node*& tail,int data){
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
node* add(node* first,node* second){
    int carry=0;
    node* anshead=NULL;
    node* anstail=NULL;
    //1st METHOD
    // while(first!=NULL&&second!=NULL){
    //     int sum=carry+first->data+second->data;
    //     int digit=sum%10;
    //     insertattail(anshead,anstail,digit);
    //     carry=sum/10;
    //     first=first->next;
    //     second=second->next;
    // }
    // while(first!=NULL){
    //     int sum=carry+first->data;
    //     int digit=sum%10;
    //     insertattail(anshead,anstail,digit);
    //     carry=sum/10;
    //     first=first->next;
    // }
    //  while(second!=NULL){
    //     int sum=carry+second->data;
    //     int digit=sum%10;
    //     insertattail(anshead,anstail,digit);
    //     carry=sum/10;
    //     second=second->next;
    // }
    // while(carry!=0){
    //     int sum=carry;
    //     int digit=sum%10;
    //     insertattail(anshead,anstail,digit);
    //     carry=sum/10;
    // }
    // return anshead;


    //2ND METHOD
    while(first!=NULL||second!=NULL||carry!=0){
        int val1=0,val2=0;
        if(first!=NULL){
            val1=first->data;
        }
        if(second!=NULL){
            val2=second->data;
        }
        int sum=val1+val2+carry;
        int digit=sum%10;
        insertattail(anshead,anstail,digit);
        carry=sum/10;
        if(first!=NULL){
            first=first->next;
        }
        if(second!=NULL){
            second=second->next;
        }
    }
    return anshead;
}
node* addtwolist(node* first,node* second){
    first=reverse(first);
    second=reverse(second);
    node* ans=add(first,second);
    ans=reverse(ans);
    return ans;
}
int main(){

    return 0;
}