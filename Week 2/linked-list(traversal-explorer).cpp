#include<iostream>
using namespace std;

class Node{
public :
int data;
Node* next;
Node(int a){
    data = a;
    next = NULL;
}
};

class ll{
Node* head = NULL;
Node* tail = NULL;
public :
void insert(const int& val){
    if(head == NULL){
        Node* n = new Node(val);
        head = n;
        tail = n;
        return;
    }
    Node* n = new Node(val);
    tail->next = n;
    tail = n;
    return;
}
void del(){
    if(head == NULL){
        throw underflow_error("ll is empty");
        return;
    }
    if(head == tail){
        Node* temp = head;
        head = head->next;
        tail = head;
        delete temp;
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
    return;
}
void func(){
    int count = 0;
    for(Node* n = head; n; n = n->next){
        count++;
        cout<<n->data;
        if(n != tail) cout<<" -> ";
    }
    cout<<" -> NULL\n";
    cout<<"The number of node in the linked list : "<<count<<'\n';
}
~ll(){
   while(head){
    Node* temp = head;
    head = head->next;
    delete temp;
   }
}
};

int main (){
    ll l;
    l.insert(5);
    l.insert(10);
    l.insert(15);
    l.insert(20);
    l.func();
    return 0;
}

/*

output:

5 -> 10 -> 15 -> 20

4

*/