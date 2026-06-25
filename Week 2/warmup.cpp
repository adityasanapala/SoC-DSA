#include <iostream>
#include <vector>
#include <stdexcept>
#include <deque>
#include <queue>
#include <unordered_set>
#include <stack>
using namespace std; 

template <typename T>
class Stack{
    private:
    vector<T> v;
    public:
    Stack(){}
    Stack(initializer_list<T> init){
        for(T x:init){
            v.push_back(x);
        }
    }
    ~Stack(){
        v.clear();
    }
    void push(const T& value){
        v.push_back(value);
    }
    void pop(){
        if(v.empty()){
            throw std::underflow_error("Stack is empty");
        }
        else v.pop_back();
    }
    T& top(){
        if(v.empty()){
            throw std::underflow_error("Stack is empty");
        }
        else return v.back();
    }
    const T& top() const{
        return v.back();
    }
    bool empty() const{
        return (v.empty());
    }
    std::size_t size() const{
        return v.size();
    }
    bool operator==(const Stack& other){
        return(v==other.v);
    }
    bool operator!=(const Stack& other){
        return(v!=other.v);
    }
    void operator<<(std::ostream&){
        std::cout<<"[";
        for(auto i=v.size()-1;i>=0;i--){
            cout<<v[i];
            if(i==0){
                cout<<"]"<<endl;
            }
            else cout<<", ";
        }
    }
};

template <typename T>
class Queue{
    private:
    deque<T> dq;
    public:
    Queue(){}
    ~Queue(){
        dq.clear();
    }
    void enqueue(const T& value){
        dq.push_back(value);
    }
    void dequeue(){
        if(dq.empty()) throw underflow_error("Queue is Empty");
        else dq.pop_front();
    }
    T& front(){
        if(dq.empty()) throw underflow_error("Queue is Empty");
        else return dq.front();
    }
    const T& front() const{
        if(dq.empty()) throw underflow_error("Queue is Empty");
        else return dq.front();
    }
    T& back(){
        if(dq.empty()) throw underflow_error("Queue is Empty");
        else return dq.back();
    }
    const T& back() const{
        if(dq.empty()) throw underflow_error("Queue is Empty");
        else return dq.back();
    }
    bool empty() const{
        return dq.empty();
    }
    std::size_t size() const{
        return dq.size();
    }
    bool operator==(const Queue& other){
        return dq==other.dq;
    }
    bool operator!=(const Queue& other){
        return dq!=other.dq;
    }
    void operator<<(std::ostream){
        cout<<"[";
        for(int i=0;i<(int)dq.size()-1;i++){
           cout<<dq[i]<<" ";
            
        }
        cout<<dq[(int)dq.size()-1]<<"]"<<endl;
    }
};

template <typename T>
class Linked_List{
    private:
    struct Node{
        T data;
        Node* next;
        Node(T val){
            data=val;
            next=nullptr;
        }
    };
    Node* head;
    public:
    Linked_List(){
        head=nullptr;
    }
    void insert(T x){
        Node* temp = new Node(x);
        if (head == nullptr) {
            head = temp;
            return;
        }
        Node* curr = head;
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = temp;

    }
    void traverse(){
        Node* temp=head;
        while(temp){
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<"NULL";
        return;
    }
    int count(){
        Node *temp=head;
        int cnt=1;
        while(temp!=NULL){
            temp=temp->next;
            cnt++;
        }
        return cnt;
    }
};


struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val){
        data=val;
        left=nullptr;
        right=nullptr;
    }
};

//root,left,right
void preorder(TreeNode* root){
    if(!root) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
//left,root,right
void inorder(TreeNode* root){
    if(!root)return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
//left,right,root
void postorder(TreeNode* root){
    if(!root)return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
void levelOrder(TreeNode* root){
    if(!root) return;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* curr = q.front(); q.pop();
            cout << curr->data<<" ";
        if (curr->left)  q.push(curr->left);
        if (curr->right) q.push(curr->right);
    }
}



int main(){
   Linked_List<int> l;
   l.insert(5);
   l.insert(10);
   l.insert(15);
   l.insert(20);
   cout<<"count="<<l.count()<<"\n";
   cout<<"Traversal: ";
   l.traverse();
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->right = new TreeNode(6);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    cout<<"Preorder Traversal: "; preorder(root);
    cout<<"\nInorder Traversal: "; inorder(root);
    cout<<"\nPostorder Traversal: "; postorder(root);
    cout<<"\nLevelorder Trversal: "; levelOrder(root);


    //Reflections
   "1. How does recursion implicitly use a stack?\n"
   "In Resursion,the function calls itself multiple times\n"
   "Each time when the function is called,the system creates a stack frame and pushed on to call stack.\n"
   "When function returns,the stack frame is popped out from this call stack in LIFO order.\n"
   
   "2. Why is a queue required for BFS?\n"
   "BFS explores graph level-by-level.A Queue follows FIFO,\n"
   "which ensures node discovered earlier processed 1st\n"
   
   "3. What are the key differences between DFS and BFS?\n"
   "BFS traverses the graph level-by-level while DFS depth-wise\n"
   "BFS uses queue while DFS uses stack\n"

   "4. Why is a visited array/set necessary in graph traversal?\n"
   "To prevent falling into loops/cycles within the graph\n"
   "by keeping the visited array each node is processed exactly once\n";
}