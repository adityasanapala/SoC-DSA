#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_set>
using namespace std;

class Stack {
     vector<int> data;
public:
    void push(int x) {
        data.push_back(x);
    }

    int pop() {
        if (empty()) throw  underflow_error("Stack is empty");
        int val = data.back();
        data.pop_back();
        return val;
    }

    int top() const {
        if (empty()) throw  underflow_error("Stack is empty");
        return data.back();
    }

    bool empty() const { return data.empty(); }

    void print() const {
         cout << "Stack (top -> bottom): [";
        for (int i = (int)data.size() - 1; i >= 0; --i) {
             cout << data[i];
            if (i != 0)  cout << ", ";
        }
         cout << "]\n";
    }
};

void testStack() {
     cout << "─── Stack ───────────────────────────────────\n";
    Stack s;

    s.push(10);  cout << "push(10)\n";
    s.push(20);  cout << "push(20)\n";
    s.push(30);  cout << "push(30)\n";

     cout << "pop() -> " << s.pop() << "\n";

    s.push(40);  cout << "push(40)\n";

     cout << "pop() -> " << s.pop() << "\n";

     cout << "top()  -> " << s.top()  << "\n";
     cout << "empty()-> " <<  boolalpha << s.empty() << "\n";
     cout << "Final  "; s.print();
     cout << "\n";
}

class Queue {
     deque<int> data;
public:
    void enqueue(int x) {
        data.push_back(x);
    }

    int dequeue() {
        if (empty()) throw  underflow_error("Queue is empty");
        int val = data.front();
        data.pop_front();
        return val;
    }

    int front() const {
        if (empty()) throw  underflow_error("Queue is empty");
        return data.front();
    }

    bool empty() const { return data.empty(); }

    void print() const {
         cout << "Queue (front -> rear): [";
        for ( size_t i = 0; i < data.size(); ++i) {
             cout << data[i];
            if (i + 1 != data.size())  cout << ", ";
        }
         cout << "]\n";
    }
};

void testQueue() {
     cout << "─── Queue ───────────────────────────────────\n";
    Queue q;

    q.enqueue(10);  cout << "enqueue(10)\n";
    q.enqueue(20);  cout << "enqueue(20)\n";
    q.enqueue(30);  cout << "enqueue(30)\n";

     cout << "dequeue() -> " << q.dequeue() << "\n";

    q.enqueue(40);  cout << "enqueue(40)\n";

     cout << "dequeue() -> " << q.dequeue() << "\n";

     cout << "front()   -> " << q.front()   << "\n";
     cout << "empty()   -> " <<  boolalpha << q.empty() << "\n";
     cout << "Final  "; q.print();
     cout << "\n";
}

struct ListNode {
    int       data;
    ListNode* next;
    ListNode(int val) : data(val), next(nullptr) {}
};

class LinkedList {
    ListNode* head;
public:
    LinkedList() : head(nullptr) {}

    ~LinkedList() {
        while (head) {
            ListNode* tmp = head;
            head = head->next;
            delete tmp;
        }
    }

    void insert(int x) {
        ListNode* node = new ListNode(x);
        if (!head) { head = node; return; }
        ListNode* curr = head;
        while (curr->next) curr = curr->next;
        curr->next = node;
    }

    void traverse() const {
        ListNode* curr = head;
        while (curr) {
             cout << curr->data;
            if (curr->next)  cout << " -> ";
            curr = curr->next;
        }
         cout << " -> NULL\n";
    }

    int count() const {
        int c = 0;
        ListNode* curr = head;
        while (curr) { ++c; curr = curr->next; }
        return c;
    }
};

void testLinkedList() {
     cout << "─── Linked List ─────────────────────────────\n";
    LinkedList list;
    list.insert(5);
    list.insert(10);
    list.insert(15);
    list.insert(20);

     cout << "Traversal: ";
    list.traverse();
     cout << "Count    : " << list.count() << "\n\n";
}

struct TreeNode {
    int       val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

class BinaryTree {
    TreeNode* root;

    void preorderHelper(TreeNode* node) {
        if (!node) return;
         cout << node->val << " ";
        preorderHelper(node->left);
        preorderHelper(node->right);
    }

    void inorderHelper(TreeNode* node) {
        if (!node) return;
        inorderHelper(node->left);
         cout << node->val << " ";
        inorderHelper(node->right);
    }

    void postorderHelper(TreeNode* node) {
        if (!node) return;
        postorderHelper(node->left);
        postorderHelper(node->right);
         cout << node->val << " ";
    }

    void deleteTree(TreeNode* node) {
        if (!node) return;
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }

public:
    BinaryTree() {
        root              = new TreeNode(1);
        root->left        = new TreeNode(2);
        root->right       = new TreeNode(3);
        root->left->left  = new TreeNode(4);
        root->left->right = new TreeNode(5);
        root->right->right= new TreeNode(6);
    }

    ~BinaryTree() { deleteTree(root); }

    void preorder()   {  cout << "Preorder   : "; preorderHelper(root);    cout << "\n"; }
    void inorder()    {  cout << "Inorder    : "; inorderHelper(root);     cout << "\n"; }
    void postorder()  {  cout << "Postorder  : "; postorderHelper(root);   cout << "\n"; }

    void levelOrder() {
         cout << "Level-order: ";
        if (!root) {  cout << "\n"; return; }
         queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* curr = q.front(); q.pop();
             cout << curr->val << " ";
            if (curr->left)  q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
         cout << "\n";
    }
};

void testTree() {
     cout << "─── Binary Tree Traversals ──────────────────\n";
    BinaryTree tree;
    tree.preorder();
    tree.inorder();
    tree.postorder();
    tree.levelOrder();
     cout << "\n";
}

const int NODES = 5;
 vector<int> adj[NODES + 1] = {
    {},           
    {2, 3},       
    {1, 4},       
    {1, 4},       
    {2, 3, 5},   
    {4}           
};

void DFS(int start) {
     unordered_set<int> visited;
     stack<int> stk;
    stk.push(start);

     cout << "DFS(" << start << "): ";
    while (!stk.empty()) {
        int node = stk.top(); stk.pop();
        if (visited.count(node)) continue;
        visited.insert(node);
         cout << node << " ";
        // Push in reverse order so smallest neighbour is processed first
        for (int i = (int)adj[node].size() - 1; i >= 0; --i)
            if (!visited.count(adj[node][i]))
                stk.push(adj[node][i]);
    }
     cout << "\n";
}

void BFS(int start) {
     unordered_set<int> visited;
     queue<int> q;
    visited.insert(start);
    q.push(start);

     cout << "BFS(" << start << "): ";
    while (!q.empty()) {
        int node = q.front(); q.pop();
         cout << node << " ";
        for (int nb : adj[node])
            if (!visited.count(nb)) {
                visited.insert(nb);
                q.push(nb);
            }
    }
     cout << "\n";
}

void testGraph() {
     cout << "─── Graph Traversals ────────────────────────\n";
    DFS(1);
    BFS(1);
     cout << "\n";
}

void printReflection() {
     cout << "─── Reflection Answers ──────────────────────\n";

     cout <<
    "Q1. How does recursion implicitly use a stack?\n"
    "    Every function call pushes a frame (local variables, parameters,\n"
    "    return address) onto the CPU call stack, and returning pops it.\n"
    "    Recursion uses this to remember prior state at each depth level,\n"
    "    which is exactly what an explicit stack does in iterative DFS.\n\n"

    "Q2. Why is a queue required for BFS?\n"
    "    BFS must explore all nodes at depth d before any at depth d+1.\n"
    "    A queue (FIFO) guarantees that the node discovered earliest is\n"
    "    processed earliest, preserving level-by-level order. A stack\n"
    "    would give DFS behaviour instead.\n\n"

    "Q3. Key differences between DFS and BFS?\n"
    "    DFS: uses a stack (or recursion), explores deep paths first,\n"
    "         O(V) space for the call stack, finds A solution fast.\n"
    "    BFS: uses a queue, explores wide (level by level), O(V) space\n"
    "         for the frontier, guarantees shortest path in unweighted graphs.\n\n"

    "Q4. Why is a visited array/set necessary in graph traversal?\n"
    "    Graphs can have cycles. Without tracking visited nodes the\n"
    "    traversal loops forever (e.g. 1->2->4->3->1->...). The visited\n"
    "    set ensures each node is processed exactly once, keeping\n"
    "    complexity at O(V + E).\n";
}

int main() {
    testStack();
    testQueue();
    testLinkedList();
    testTree();
    testGraph();
    printReflection();
    return 0;
}