#include <iostream>
#include <queue>
using namespace std;

// NODE, ROOT, PARENT, CHILDREN, SIBLINGS, ANCESTORS, DESCENDANTS, LEAF

class node{
public:
    int data;
    node* left;
    node* right;

    node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

node* buildtree(node* root){
    cout << "Enter the data" << endl;
    int data;
    cin >> data;

    root = new node(data);

    if(data == -1){
        return NULL;
    }

    cout << "Enter data for inserting in left of " << data << endl;
    root->left = buildtree(root->left);

    cout << "Enter data for inserting in right of " << data << endl;
    root->right = buildtree(root->right);

    return root;
}

void LevelOrderTraversal(node* root){
    queue<node*> q;

    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        if(temp == NULL){
            cout << endl;

            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout << temp->data << " ";

            if(temp->left){
                q.push(temp->left);
            }

            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}

// INORDER
void inorder(node* root){
    if(root == NULL){
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// PREORDER
void preorder(node* root){
    if(root == NULL){
        return;
    }

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// POSTORDER
void postorder(node* root){
    if(root == NULL){
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

void buildfromlevelorder(node* &root){
    queue<node*> q;

    cout << "Enter data for root" << endl;
    int data;
    cin >> data;

    root = new node(data);
    q.push(root);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        cout << "Enter the left node for: " << temp->data << endl;
        int leftdata;
        cin >> leftdata;

        if(leftdata != -1){
            temp->left = new node(leftdata);
            q.push(temp->left);
        }

        cout << "Enter the right node for: " << temp->data << endl;
        int rightdata;
        cin >> rightdata;

        if(rightdata != -1){
            temp->right = new node(rightdata);
            q.push(temp->right);
        }
    }
}
int main(){
    node* root = NULL;
    // Build tree using level order input
    buildfromlevelorder(root);

    cout << "\nLevel Order Traversal:\n";
    LevelOrderTraversal(root);

    // cout << "\nInorder Traversal:\n";
    // inorder(root);

    // cout << "\n\nPreorder Traversal:\n";
    // preorder(root);

    // cout << "\n\nPostorder Traversal:\n";
    // postorder(root);

    cout << endl;

    return 0;
}