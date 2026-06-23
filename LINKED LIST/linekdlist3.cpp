#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* next;

    // Constructor
    node(int d) {
        this->data = d;
        this->next = NULL;
    }

    // Destructor
    ~node() {
        int val = this->data;
        cout << "Memory is free for node with data " << val << endl;
    }
};
// Print Circular Linked List
void print(node* tail) {
    if (tail == NULL) {
        cout << "List is empty" << endl;
        return;
    }
    
    node* temp = tail;

    // do-while is MUST for circular LL
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != tail);

    cout << endl;
}

// Insert node after given element
void insertnode(node*& tail, int element, int val) {

    // Empty list
    if (tail == NULL) {
        node* newnode = new node(val);
        tail = newnode;
        newnode->next = newnode;
        return;
    }

    node* curr = tail;
    // Traverse circular li
    // st
    do {
        if (curr->data == element) {
            node* temp = new node(val);
            temp->next = curr->next;
            curr->next = temp;
            return;
        }
        curr = curr->next;
    } while (curr != tail);

    cout << "Element not found!" << endl;
}

// Delete node with given value

void deletenode(node* &tail,int element){
    if(tail==NULL){
        cout<<" list is empty , chck again"<<endl;

    }
    else{
    node* prev=tail;
    node* curr=tail->next;
    while(curr->data!=element){
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

int main() {

    node* tail = NULL;

    // Insert operations
    insertnode(tail, 5, 3);   // first node
    print(tail);

    insertnode(tail, 3, 5);
    print(tail);
    insertnode(tail,3,7);
    print(tail);
    deletenode(tail,7);
    print(tail);
    return 0;
}