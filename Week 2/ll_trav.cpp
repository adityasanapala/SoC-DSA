#include <bits/stdc++.h>
#include <stdexcept>
using namespace std;
typedef long long ll;

ofstream my_file("ll_trav.txt");

class Node{
    public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = nullptr;
    }
};

class List{
    Node* head;
    Node* tail;

    public:
    List(){
        head = tail = nullptr;
    }

    void push_front(int val){
        Node* newNode = new Node(val);
        if(head == nullptr){
            head = tail = newNode;
        }
        else{
            newNode->next = head;
            head = newNode;
        }
    }
    void push_back(int val){
        Node* newNode = new Node(val);
        if(tail == nullptr){
            head = tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
    }
    void pop_front(){
        if(head == nullptr){
            throw underflow_error("List is empty");
        }
        else{
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
    void pop_back(){
        if(head == nullptr){
            throw underflow_error("List is empty");
        }
        else{
            Node* temp = head;
            while(temp->next != tail){
                temp = temp->next;
            }
            temp->next = nullptr;
            delete tail;
            tail = temp;
        }
    }

    void printLL(){
        Node* temp = head;
        while(temp != nullptr){
            my_file << temp->data << "->";
            temp = temp -> next;
        }
        my_file << "NULL\n";
    }

    int count(){
        int count = 0;
        Node* temp = head;
        while(temp != nullptr){
            temp = temp -> next;
            count++;
        }
        return count;
    }
    
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    
    List ll;
    ll.push_front(5);
    ll.push_front(10);
    ll.push_front(15);
    ll.push_front(20);

    ll.printLL();
    my_file << ll.count() <<endl;

    ll.pop_back();
    ll.printLL();
    my_file << ll.count() <<endl;
    ll.push_back(25);
    ll.printLL();
    my_file << ll.count() <<endl;
    ll.pop_front();
    ll.printLL();
    my_file << ll.count() <<endl;

    return 0;
}
