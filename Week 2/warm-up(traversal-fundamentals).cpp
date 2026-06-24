#include<iostream>
#include<vector>
#include<queue>
#include<list>
#include<algorithm>
using namespace std;

template<typename T>
class Stack{

vector<T> s;

public:

void push(const T& val){
    s.push_back(val);
}

T pop(){
    if(s.size() == 0){
        throw underflow_error("Stack is empty");
    }
    T val = s.back();
    s.pop_back();
    return val;
}

T& top(){
    if(s.size() == 0){
        throw underflow_error("Stack is empty");
    }
    return s.back();
}

bool empty(){
    return (s.size() == 0);
}

void print(){
    for(int i = 0; i < s.size(); i++){
        cout<<s[i]<<" ";
    }
    cout<<'\n';
}
};

template<typename T>
class Node{

    public :

    T data;
    Node<T>* next;

    Node(const T& val){
        data = val;
        next = NULL;
    }

};

template<typename T>
class Queue{

    Node<T>* f = NULL;
    Node<T>* rear = NULL;

    public : 

    void enqueue(const T& val){
        if(f == NULL){
            Node<T>* n = new Node<T>(val);
            f = n;
            rear = n;
            return;
        }
        Node<T>* n = new Node<T>(val);
        rear->next = n;
        rear = n;
        return;
    }

    T dequeue(){
        if(f == NULL){
            throw underflow_error("Queue is empty");
        }
        Node<T>* temp = f;
        T val = f->data;
        f = f->next;
        delete temp;
        if(f == NULL) rear = NULL;
        return val;
    }

    T& front(){
        if(f == NULL){
            throw underflow_error("Queue is empty");
        }
        T& val = f->data;
        return val;
    }

    bool empty(){
        return (f == NULL);
    }
    ~Queue(){
        while(!empty()){
            dequeue();
        }
    }

    void print(){
        for(Node<T>* n = f; n; n = n->next){
            cout<<n->data<<" ";
        }
        cout<<'\n';
    }

};

template<typename T>
class ll{
    Node<T>* head = NULL;
    Node<T>* tail = NULL;
    public : 
    void insert(const T& val){
        if(head == NULL){
            Node<T>* n = new Node<T>(val);
            head = n;
            tail = n;
            return;
        }
        Node<T>* n = new Node<T>(val);
        tail->next = n;
        tail = n;
        return;
    }
    void traverse(){
        for(Node<T>* n = head; n; n = n->next){
            cout<<n->data;
            if(n != tail){
                cout<<" -> ";
            }
        }
        cout<<" -> NULL";
        cout<<'\n';
    }
    int count(){
        int c = 0;
        for(Node<T>* n = head; n; n = n->next){
            c++;
        }
        return c;
    }
};

class N{
    public :
    int data;
    N* left;
    N* right;
    N(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

N* buildTree(){
    N* root = new N(1);
    root->left = new N(2);
    root->right = new N(3);
    root->left->left = new N(4);
    root->left->right = new N(5);
    root->right->right = new N(6);
    return root;
}

void preorder(N* root){
    if(root == NULL) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(N* root){
    if(root == NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void postorder(N* root){
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

void levelorder(N* root){
    queue<N*> q;
    q.push(root);
    while(q.size() > 0){
        N* curr = q.front();
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

class graph{
    int v;
    list<int>* l;
    public:
    graph(int v){
        this->v = v;
        l = new list<int>[v+1];
    }

    void addEdge(int u, int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void bfs(int x){
        vector<bool> vis(v+1);
        queue<int> q;
        q.push(x);
        vis[x] = true;
        while(q.size() > 0){
            int u = q.front();
            q.pop();
            cout<<u<<" ";
            for(int y : l[u]){
                if(!vis[y]){
                    vis[y] = true;
                    q.push(y);
                }
            }
        }
    }

    void dfsHelper(int x, vector<bool>& vis){
        cout<<x<<" ";
        vis[x] = true;
        for(int y : l[x]){
            if(!vis[y]){
                dfsHelper(y, vis);
            }
        }
    }

    void dfs(int u){
        int x = u;
        vector<bool> vis(v+1);
        dfsHelper(x, vis);
    }
};

int main(){

    Stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.pop();
    s.push(40);
    s.pop();
    s.print();

    Queue<int> q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.dequeue();
    q.enqueue(40);
    q.dequeue();
    q.print();

    ll<int> l;
    l.insert(5);
    l.insert(10);
    l.insert(15);
    l.insert(20);
    l.traverse();
    cout<<l.count()<<endl;

   N* root = buildTree();
   preorder(root);
   cout<<endl;
   inorder(root);
   cout<<endl;
   postorder(root);
   cout<<endl;
   levelorder(root);
   cout<<endl;

   graph g(5);
   g.addEdge(1,2);
   g.addEdge(1,3);
   g.addEdge(2,4);
   g.addEdge(3,4);
   g.addEdge(4,5);

   g.bfs(1);
   cout<<endl;
   g.dfs(1);
   cout<<endl;

    return 0;
}