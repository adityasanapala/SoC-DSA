#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <stdexcept>
#include <initializer_list>

using namespace std;

template <typename T>
class Stack {
private:
    vector<T> data;

public:
    Stack() = default;
    ~Stack() = default;

    Stack(initializer_list<T> init) {
        for (const auto& value : init) {
            push(value);
        }
    }

    void push(const T& value) {
        data.push_back(value);
    }

    void pop() {
        if (empty()) {
            throw underflow_error("Stack is empty");
        }

        data.pop_back();
    }
    T& top() {
        if (empty()) {
            throw underflow_error("Stack is empty");
        }

        return data.back();
    }

    const T& top() const {
        if (empty()) {
            throw underflow_error("Stack is empty");
        }

        return data.back();
    }

    bool empty() const {
        return data.empty();
    }

    size_t size() const {
        return data.size();
    }

    bool operator==(const Stack& other) const {
        return data == other.data;
    }

    bool operator!=(const Stack& other) const {
        return !(*this == other);
    }

    friend ostream& operator<<(ostream& os, const Stack& s) {
        os << "[";

        for (int i = static_cast<int>(s.data.size()) - 1; i >= 0; --i) {
            os << s.data[i];

            if (i > 0) {
                os << ", ";
            }
            }

        os << "]";
        return os;
    }
};

template <typename T>
class Queue {
private:
    deque<T> data;

public:
    Queue() = default;
    ~Queue() = default;

    void enqueue(const T& value) {
        data.push_back(value);
    }

    void dequeue() {
        if (empty()) {
            throw underflow_error("Queue is empty");
        }

        data.pop_front();
    }

    T& front() {
        if (empty()) {
            throw underflow_error("Queue is empty");
        }

        return data.front();
    }
    const T& front() const {
        if (empty()) {
            throw underflow_error("Queue is empty");
        }

        return data.front();
    }

    T& back() {
        if (empty()) {
            throw underflow_error("Queue is empty");
        }

        return data.back();
    }
    const T& back() const {
        if (empty()) {
            throw underflow_error("Queue is empty");
        }

        return data.back();
    }

    bool empty() const {
        return data.empty();
    }

    size_t size() const {
        return data.size();
    }

    bool operator==(const Queue& other) const {
        return data == other.data;
    }

    bool operator!=(const Queue& other) const {
        return !(*this == other);
    }

    friend ostream& operator<<(ostream& os, const Queue& q) {
        os << "[";

        for (size_t i = 0; i < q.data.size(); ++i) {
            os << q.data[i];

            if (i != q.data.size() - 1) {
                os << ", ";
            }
        }

        os << "]";
        return os;
    }
};
template <typename T>
class CircularQueue {
private:
    vector<T> data;
    size_t head;
    size_t tail;
    size_t count;
    size_t capacity;

public:
    explicit CircularQueue(size_t cap)
        : data(cap),
          head(0),
          tail(0),
          count(0),
          capacity(cap) {}

    void enqueue(const T& value) {
        if (count == capacity) {
            throw overflow_error("Queue is full");
        }

        data[tail] = value;
        tail = (tail + 1) % capacity;
        ++count;
    }

    void dequeue() {
        if (count == 0) {
            throw underflow_error("Queue is empty");
        }

        head = (head + 1) % capacity;
        --count;
    }

    T& front() {
        if (count == 0) {
            throw underflow_error("Queue is empty");
        }

        return data[head];
    }

    bool empty() const {
        return count == 0;
    }

    size_t size() const {
        return count;
    }
};
struct Node {
    int data;
    Node* next;

    explicit Node(int value)
        : data(value), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    ~LinkedList() {
        Node* current = head;

        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }

    void insert(int value) {
        Node* newNode = new Node(value);

        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* current = head;

        while (current->next != nullptr) {
            current = current->next;
        }

        current->next = newNode;
    }
    void traverse() const {
        Node* current = head;

        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }

        cout << "NULL\n";
    }

    int count() const {
        int cnt = 0;
        Node* current = head;

        while (current != nullptr) {
            ++cnt;
            current = current->next;
        }

        return cnt;
    }
};

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    explicit TreeNode(int value)
        : data(value), left(nullptr), right(nullptr) {}
};

void preorder(TreeNode* root) {
    if (!root) return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(TreeNode* root) {
    if (!root) return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(TreeNode* root) {
    if (!root) return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}
void levelOrder(TreeNode* root) {
    if (!root) return;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();

        cout << current->data << " ";

        if (current->left) q.push(current->left);
        if (current->right) q.push(current->right);
    }
}

class Graph {
private:
    unordered_map<int, vector<int>> adj;

public:
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void DFS(int start) {
        unordered_set<int> visited;
        stack<int> st;

        st.push(start);

        while (!st.empty()) {
            int node = st.top();
            st.pop();

            if (visited.count(node)) {
                continue;
            }

            visited.insert(node);
            cout << node << " ";

            for (auto it = adj[node].rbegin();
                 it != adj[node].rend();
                 ++it) {

                if (!visited.count(*it)) {
                    st.push(*it);
                }
            }
        }

        cout << '\n';
    }
void BFS(int start) {
        unordered_set<int> visited;
        queue<int> q;

        visited.insert(start);
        q.push(start);

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            cout << node << " ";

            for (int neighbor : adj[node]) {
                if (!visited.count(neighbor)) {
                    visited.insert(neighbor);
                    q.push(neighbor);
                }
            }
        }

        cout << '\n';
    }
};

int main() {

    Stack<int> s;

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "pop(): " << s.top() << '\n';
    s.pop();

    s.push(40);

    cout << "pop(): " << s.top() << '\n';
    s.pop();

    cout << "Final stack (top->bottom): " << s << "\n\n";

    Queue<int> q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "dequeue(): " << q.front() << '\n';
    q.dequeue();

    q.enqueue(40);

    cout << "dequeue(): " << q.front() << '\n';
    q.dequeue();

    cout << "Final queue (front->back): " << q << "\n\n";

    LinkedList list;

    list.insert(5);
    list.insert(10);
    list.insert(15);
    list.insert(20);

    cout << "Traversal: ";
    list.traverse();

    cout << "Node count: " << list.count() << "\n\n";

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    root->right->right = new TreeNode(6);

    cout << "Preorder: ";
    preorder(root);
    cout << '\n';

    cout << "Inorder: ";
    inorder(root);
    cout << '\n';

    cout << "Postorder: ";
    postorder(root);
    cout << '\n';

    cout << "Level-order: ";
    levelOrder(root);
    cout << "\n\n";

    
    Graph g;

    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 4);
    g.addEdge(4, 5);

    cout << "DFS from 1: ";
    g.DFS(1);

    cout << "BFS from 1: ";
    g.BFS(1);

    delete root->left->left;
    delete root->left->right;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}