#include<iostream>
using namespace std;

template<typename T>
class Node{
    public :
    T data;
    Node<T>* next = NULL;
};

template<typename T>
class Queue{

    Node<T>* head = NULL;
    Node<T>* tail = NULL;

    public:

    Queue(){};

    void enqueue(const T& value){
        if(head == NULL){
            Node<T>* n = new Node<T>;
            n->data = value;
            head = n;
            tail = n;
            return;
        }
        if(head != NULL){
            Node<T>* n = new Node<T>;
            n->data = value;
            tail->next = n;
            tail = n;
            return;
        }
    }

    void dequeue(){
        if(head == NULL){
            throw underflow_error("Queue is empty");
            return;
        }
        if(head == tail){
        Node<T>* n = head;
        head = head->next;
        tail = head;
        delete n;
        return;
        }
        Node<T>* n = head;
        head = head->next;
        delete n;
        return;
    }

    T& front(){
        if(head == NULL){
            throw underflow_error("Queue is empty");
        }else{
        return head->data;
        }
    }

    const T& front() const{
        if(head == NULL){
        throw underflow_error("Queue is empty");
        }else{
        return head->data;
        }
    }

    T& back(){
        if(head == NULL){
            throw underflow_error("Queue is empty");
        }else{
            return tail->data;
        }
    }

    const T& back() const{
        if(head == NULL){
            throw underflow_error("Queue is empty");
        }else{
            return tail->data;
        }
    }

    bool empty() const{
        return head == nullptr;
    }

    size_t size() const{
        if(head == NULL) return 0;
        size_t count = 0;
        for(Node<T>* n = head; n; n = n->next){
            count++;
        }
        return count;
    }

    ~Queue(){
        while(!empty()){
            dequeue();
        }
    }

    bool operator==(const Queue& q) const{
        if(this->size() != q.size()) return false;
        Node<T>* n1 = head;
        Node<T>* n2 = q.head;
        for(int i = 0; i < this->size(); i++){
            if(n1->data != n2->data) return false;
            n1 = n1->next;
            n2 = n2->next;
        }
        return true;
    }

    bool operator!=(const Queue& q) const{
        if(this->size() != q.size()) return true;
        Node<T>* n1 = head;
        Node<T>* n2 = q.head;
        for(int i = 0; i < this->size(); i++){
            if(n1->data != n2->data) return true;
            n1 = n1->next;
            n2 = n2->next;
        }
        return false;
    }

    friend ostream& operator<<(ostream& cout, Queue& q){
        cout<<"[";
        for(Node<T>* n = q.head; n; n = n-> next){
            cout<<n->data;
            if(n != q.tail) cout<<", ";
        }
        cout<<"]";
        return cout;
    }

};
//----------------------------------------------------------------------------------------------------------------------------------
template<typename T>
class CircularQueue{
T* arr;
int head = -1;
int tail = -1;
int capacity = 0;
public :
CircularQueue(int a){
    capacity = a;
    arr = new T[capacity];
}
void enqueue(const T& value){
    int a = tail;
    if((a+1) % capacity == head){
        throw overflow_error("Circular Queue is full");
        return;
    }
    tail++;
    if(tail >= capacity){
        tail = tail%capacity;
    }
    arr[tail] = value;
    if(head == -1){
        head++;
        arr[head] = value;
    }
    return;
}
void dequeue(){
  if(head == -1){
    throw underflow_error("Circular Queue is empty");
    return;
  }
  if(head == tail){
    head = -1;
    tail = -1;
    return;
  }
  head++;
  if(head >= capacity){
    head = head%capacity;
  }
  return;
}
    T& front(){
        if(head == -1){
            throw underflow_error("Circular Queue is empty");
        }else{
        return arr[head];
        }
    }
    const T& front() const{
        if(head == -1){
            throw underflow_error("Circular Queue is empty");
        }else{
        return arr[head];
        };
    }
    T& back(){
        if(head == -1){
            throw underflow_error("Circular Queue is empty");
        }else{
        return arr[tail];
        }
    }
    const T& back() const{
        if(head == -1){
            throw underflow_error("Circular Queue is empty");
        }else{
        return arr[tail];
        }
    }
    bool empty() const{
        if(head == -1) return true;
        else return false;
    }
    size_t size() const{
        if(head == -1) return 0;
      if(tail > head) return (tail - head + 1);
      if(head == tail) return 1;
      if(head > tail) return (((tail - 0) + 1) + ((capacity-1) - (head) +1));
      return 0;
    }
    bool operator==(const CircularQueue& q){
        if(q.size() != this->size()) return false;
        for(size_t i = 0; i < this->size(); i++){
            if(this->arr[(i+head)%capacity] != q.arr[(i+q.head)%q.capacity]) return false;
        }
        return true;
    }
    bool operator!=(const CircularQueue& q){
        if(q.size() != this->size()) return true;
        for(size_t i = 0; i < this->size(); i++){
            if(this->arr[(i+head)%capacity] != q.arr[(i+q.head)%q.capacity]) return true;
        }
        return false;
    }
    friend ostream& operator<<(ostream& cout, CircularQueue& q){
        cout<<"[";
        for(int i = 0; i < q.size(); i++){
            cout<<q.arr[(i+q.head)%q.capacity];
            if(i+1 != q.size()) cout<<", ";
        }
        cout<<"]";
        return cout;
    }
    ~CircularQueue(){
        delete[] arr;
    }
};

int main(){
    return 0;
}