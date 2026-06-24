#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ofstream my_file("tree.txt");
/*solve(root){
 *  solve(left subtree)
 *  solve(right subtree)
 *  find the solution for the root
 * } */

/*Given binary tree
 *       1
        / \
        2   3
       / \   \
      4   5   6
 */

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

static int idx = -1;

Node* buildTree(vector<int> preOrder){
    idx++;
    if(preOrder[idx] == -1) return nullptr;
    Node* root = new Node(preOrder[idx]);
    root->left = buildTree(preOrder);
    root->right = buildTree(preOrder);
    return root;
}

//root, left, right
void preorder(Node* root){
    if(root == nullptr){
        my_file << "-1 ";
        return;
    }
    my_file << root->data <<" ";
    preorder(root->left);
    preorder(root->right);
}

//left, root, right
void inorder(Node* root){
    if(root == nullptr){
        my_file << "-1 ";
        return;
    }
    inorder(root->left);
    my_file << root->data <<" ";
    inorder(root->right);
}

//left, right, root
void postorder(Node* root){
    if(root == nullptr){
        my_file << "-1 ";
        return;
    }
    postorder(root->left);
    postorder(root->right);
    my_file << root-> data<<" ";
}

void levelorder(Node* root){
    queue<Node*> q;
    q.push(root);

    while(q.size() > 0){
        Node* curr = q.front();
        q.pop();
        my_file << curr->data <<" ";

        if(curr->left != nullptr){
            q.push(curr->left);
        }
        if(curr->right != nullptr){
            q.push(curr->right);        
        }
    }
    my_file <<endl;
}

void levelorder_inlines(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(nullptr);

    while(q.size() > 0){
        Node* curr = q.front();
        q.pop();
        if(curr == nullptr){
            // line is completed
            if(!q.empty()){
                my_file << endl;
                q.push(nullptr);
                continue;
            }
            // fully traversed
            else{
                break;
            }
        }
        my_file << curr->data <<" ";

        if(curr->left != nullptr){
            q.push(curr->left);
        }
        if(curr->right != nullptr){
            q.push(curr->right);        
        }
    }
    my_file <<endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> preOrder = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};

    Node* root = buildTree(preOrder);

    // my_file << root->data <<endl;
    // my_file << root->left->data <<endl;
    // my_file << root->right->right->data <<endl;
    my_file << "preorder traversal : ";
    preorder(root); //should be the same as preOrder
    my_file << endl;
    my_file << "inorder traversal : ";
    inorder(root); // should give {-1, 4, -1, 2, -1, 5, -1, 1, -1, 3, -1, 6, -1}
    my_file << endl;
    my_file << "postorder traversal : ";
    postorder(root); //should give {-1, -1, 4, -1, -1, 5, 2, -1, -1, -1, 6, 3, 1}
    my_file <<endl;
    my_file << "levelorder traversal : ";
    levelorder(root); //should give {1, 2, 3, 4, 5, 6}
    my_file << "inorder traversal in separate lines: ";
    levelorder_inlines(root); //should give {1 \n 2 3 \n 4 5 6} 
    return 0;
}
