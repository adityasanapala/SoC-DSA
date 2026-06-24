#include<iostream>
#include<queue>
using namespace std;

class Node{
    public :
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};
void preorder(Node* root){
    if(root == NULL) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root){
    if(root == NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void postorder(Node* root){
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

void levelorder(Node* root){
    queue<Node*> q;
    q.push(root);
    while(q.size() > 0){
    Node* curr = q.front();
    q.pop();
    cout<<curr->data<<" ";
    if(curr->left != NULL){
        q.push(curr->left);
    }
    if(curr->right != NULL){
        q.push(curr->right);
    }
}
}


int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    preorder(root);
    cout<<endl;
    inorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;
    levelorder(root);
    cout<<endl;

    return 0;
}

/*

output:

preorder traversal : 1 2 4 5 3 6
inorder traversal : 4 2 5 1 3 6
postorder traversal : 4 5 2 6 3 1
levelorder traversal : 1 2 3 4 5 6

*/