//REVERSING THE LINKED LISTS

#include <iostream>
using namespace std;
#include <map>
class node{
public:
    int data;
    node* next;

    node(int data){
        this->data = data;
        this->next = NULL;
    }

    ~node(){
        cout << "the memory is cleared with data " << data << endl;
    }
};

int getLength(node* head) {
    int len = 0;
    node* temp = head;

    while(temp != NULL) {
        len++;
        temp = temp->next;
    }

    return len;
}

node* getmiddle(node* head){

    if(head == NULL || head->next == NULL){
        return head;
    }

    if(head->next->next == NULL){
        return head->next;
    }

    node* slow = head;
    node* fast = head->next;

    while(fast != NULL){
        fast = fast->next;

        if(fast != NULL){
            fast = fast->next;
        }

        slow = slow->next;
    }

    return slow;
}

node* reverse1(node* &head){

    if(head == NULL || head->next == NULL){
        return head;
    }

    node* chotahead = reverse1(head->next);

    head->next->next = head;
    head->next = NULL;

    return chotahead;
}

void reverse(node* &head, node* curr, node* prev){

    if(curr == NULL){
        head = prev;
        return;
    }

    node* forward = curr->next;

    curr->next = prev;

    reverse(head, forward, curr);
}

void insertnode(node* &tail, int element, int d){

    // empty list
    if(tail == NULL){
        node* temp = new node(d);
        tail = temp;
        temp->next = temp;
        return;
    }

    node* curr = tail;

    do{
        if(curr->data == element)
            break;

        curr = curr->next;

    }while(curr != tail);

    node* temp = new node(d);

    temp->next = curr->next;
    curr->next = temp;
}

node* reverselinkedlist(node* head){

    if(head == NULL || head->next == NULL){
        return head;
    }

    node* prev = NULL;
    node* curr = head;
    node* forward = NULL;

    while(curr != NULL){

        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }

    return prev;
}

void print(node* head){

    node* temp = head;

    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

node* Kreverse(node* head, int k){

    if(head == NULL){
        return NULL;
    }

    // reverse first k nodes
    node* next = NULL;
    node* curr = head;
    node* prev = NULL;

    int count = 0;

    while(curr != NULL && count < k){

        next = curr->next;
        curr->next=prev;
        prev=curr;
       curr = next;
        count++;
    }

    // recursion
    if(next != NULL){
        head->next = Kreverse(next, k);
    }

    return prev;
}
bool CHECK(node* head){
    node* temp=head;
    int len=getLength(head),cnt=0;
    if(head==NULL){
        return true;
    }
    else if(head->next==head){
        return true;
    }
    temp=temp->next;
    while(temp->next!=head&&temp!=NULL){
        temp=temp->next;
        if(temp==NULL){
            return false;
        }
    }
    return true;
}
bool detectloop(node* head){
    if(head==NULL){
        return false;
    }
    map<node*,bool> visited;
    node* temp=head;
    while(temp!=NULL){
        if(visited[temp]==true){
            cout<<temp->data;
            return true;
        }
        visited[temp]=true ;
        temp=temp->next;
    }
    return false;
}
bool floyd(node* head){
    node* first=head;
    node* second=head;
    node* curr=head->next;
    if(head==NULL||head->next==NULL){
        return true;
    }
    while(second!=NULL&&curr!=NULL){
        curr=second->next;
        first=first->next;
        second=curr->next;
        if(first==second){
            cout<<"STARTING IS HERE"<<first->data;
            return true;
        }
    }
    return false;
}
node* getstartingnode(node* head){
    if(head==NULL){
        return NULL;
    }
    node* intersection=floyd(node* head);//  there is a prblemm in returnn fncn of floyds correct it
    node* slow=head;
    while(slow!=intersection){
        slow=slow->next;
        intersection=interesection->next;
    }

}
void removeloop(node* head){
    if(head==NULL){
        return;
    }
    node* strt=getstartingnode(head);
    node* temp=strt;
    temp=temp->next;
    while(temp->next!=strt){
        temp=temp->next;
    }
    temp->next=NULL;
}
int main(){

    // normal singly linked list
    node* head = new node(5);

    node* second = new node(6);
    node* third = new node(7);
    node* fourth = new node(8);

    head->next = second;
    second->next = third;
    third->next = fourth;
    cout << "Original Linked List: " <<endl;
    //print(head);

    head = Kreverse(head, 3);

    cout << "After K Reverse: " <<endl;
   // print(head);
    cout<<CHECK(head)<<endl;
    //print(head);
    fourth->next=second;
    if(detectloop(head)){
        cout<<" YES!!!!!!!";
    }
    else cout<<" NO!!!";
    cout<<endl;
    if(floyd(head)){
        cout<<"       MIL GYA";
    }
    else{
        cout<<"NOT PRESENT HERE";
    }
    return 0;
}