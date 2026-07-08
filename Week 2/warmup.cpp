#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <stdexcept>

using namespace std;

//====================================================
// PART 1 : STACK
//====================================================

template <typename T>
class Stack {

private:
    vector<T> data;

public:

    Stack() {}

    Stack(initializer_list<T> list) {

        for (T x : list)
            data.push_back(x);
    }

    void push(const T &value) {

        data.push_back(value);
    }

    void pop() {

        if (empty())
            throw underflow_error("Stack is empty");

        data.pop_back();
    }

    T& top() {

        if (empty())
            throw underflow_error("Stack is empty");

        return data.back();
    }

    bool empty() const {

        return data.empty();
    }

    size_t size() const {

        return data.size();
    }

    friend ostream& operator<<(ostream &out,const Stack &s){

        out<<"[";

        for(int i=s.data.size()-1;i>=0;i--){

            out<<s.data[i];

            if(i!=0)
                out<<", ";
        }

        out<<"]";

        return out;
    }
};

//====================================================
// PART 1 : QUEUE
//====================================================

template <typename T>
class Queue {

private:

    deque<T> data;

public:

    void enqueue(const T &value){

        data.push_back(value);
    }

    void dequeue(){

        if(empty())
            throw underflow_error("Queue is empty");

        data.pop_front();
    }

    T& front(){

        return data.front();
    }

    T& back(){

        return data.back();
    }

    bool empty() const{

        return data.empty();
    }

    size_t size() const{

        return data.size();
    }

    friend ostream& operator<<(ostream &out,const Queue &q){

        out<<"[";

        for(int i=0;i<q.data.size();i++){

            out<<q.data[i];

            if(i!=q.data.size()-1)
                out<<", ";
        }

        out<<"]";

        return out;
    }
};

//====================================================
// PART 2 : LINKED LIST
//====================================================

struct ListNode{

    int data;
    ListNode *next;
};

//====================================================
// PART 3 : TREE
//====================================================

struct TreeNode{

    int data;

    TreeNode *left;

    TreeNode *right;
};

void preorder(TreeNode *root){

    if(root==nullptr)
        return;

    cout<<root->data<<" ";

    preorder(root->left);

    preorder(root->right);
}

void inorder(TreeNode *root){

    if(root==nullptr)
        return;

    inorder(root->left);

    cout<<root->data<<" ";

    inorder(root->right);
}

void postorder(TreeNode *root){

    if(root==nullptr)
        return;

    postorder(root->left);

    postorder(root->right);

    cout<<root->data<<" ";
}

void levelorder(TreeNode *root){

    queue<TreeNode*> q;

    q.push(root);

    while(!q.empty()){

        TreeNode *cur=q.front();

        q.pop();

        cout<<cur->data<<" ";

        if(cur->left)
            q.push(cur->left);

        if(cur->right)
            q.push(cur->right);
    }
}

//====================================================
// PART 4 : GRAPH
//====================================================

vector<int> graph[6];

bool visited[6];

void dfs(int node){

    visited[node]=true;

    cout<<node<<" ";

    for(int next:graph[node]){

        if(!visited[next])

            dfs(next);
    }
}

//====================================================
// MAIN
//====================================================

int main(){

//====================================================
// STACK TEST
//====================================================

    cout<<"========== STACK ==========\n";

    Stack<int> s;

    s.push(10);
    s.push(20);
    s.push(30);

    s.pop();

    s.push(40);

    s.pop();

    cout<<"Final Stack : "<<s<<endl;

    cout<<"\n";

//====================================================
// QUEUE TEST
//====================================================

    cout<<"========== QUEUE ==========\n";

    Queue<int> q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.dequeue();

    q.enqueue(40);

    q.dequeue();

    cout<<"Final Queue : "<<q<<endl;

    cout<<"\n";

//====================================================
// LINKED LIST TEST
//====================================================

    cout<<"========== LINKED LIST ==========\n";

    ListNode *head=new ListNode{5,nullptr};

    head->next=new ListNode{10,nullptr};

    head->next->next=new ListNode{15,nullptr};

    head->next->next->next=new ListNode{20,nullptr};

    ListNode *temp=head;

    int count=0;

    while(temp!=nullptr){

        cout<<temp->data<<" ";

        count++;

        temp=temp->next;
    }

    cout<<"\nNodes = "<<count<<endl;

    cout<<"\n";

//====================================================
// TREE TEST
//====================================================

    cout<<"========== TREE ==========\n";

    TreeNode *root=new TreeNode{1};

    root->left=new TreeNode{2};

    root->right=new TreeNode{3};

    root->left->left=new TreeNode{4};

    root->left->right=new TreeNode{5};

    root->right->right=new TreeNode{6};

    cout<<"Preorder   : ";
    preorder(root);

    cout<<"\nInorder    : ";
    inorder(root);

    cout<<"\nPostorder  : ";
    postorder(root);

    cout<<"\nLevelorder : ";
    levelorder(root);

    cout<<"\n\n";

//====================================================
// GRAPH TEST
//====================================================

    cout<<"========== GRAPH ==========\n";

    graph[1]={2,3};

    graph[2]={1,4};

    graph[3]={1,4};

    graph[4]={2,3,5};

    graph[5]={4};

    cout<<"DFS : ";

    dfs(1);

    cout<<"\n";

    for(int i=1;i<=5;i++)
        visited[i]=false;

    queue<int> bfs;

    bfs.push(1);

    visited[1]=true;

    cout<<"BFS : ";

    while(!bfs.empty()){

        int cur=bfs.front();

        bfs.pop();

        cout<<cur<<" ";

        for(int next:graph[cur]){

            if(!visited[next]){

                visited[next]=true;

                bfs.push(next);
            }
        }
    }

    cout<<"\n";

    return 0;
}