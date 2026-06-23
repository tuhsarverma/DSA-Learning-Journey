#include <iostream>
#include <queue>
using namespace std;
//  NODE, ROOT, PARENT, CHILDREN, SIBLINGS, ANCESTORS, DESCENDANTS, LEAF
class node{
    public:
    int data;
    node* left;
    node* right;
    node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};
node* buildtree(node* root){
    cout<<" Enter the data"<<endl;
    int data;
    cin>>data;
    root =new node(data);
    if(data==-1){
        return NULL;
    }
    cout<<" enter data for inserting in left of"<<data<<endl;
    root->left=buildtree(root->left);
    cout<<" enter data for inserting in right of"<<data<<endl;
    root->right=buildtree(root->right);
    return root;
}
void LevelOrderTraversal(node* root){
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node* temp=q.front();
        cout<<temp->data<<" ";
        q.pop();
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
    }
}
int main(){
    node* root =NULL;
//   creating a tree
    root= buildtree(root);
//  level Order tre-
    LevelOrderTraversal(root);
    return 0;
}