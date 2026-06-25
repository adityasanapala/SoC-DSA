#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Queue {
    vector<T> q;
    public :
      Queue()=default;
      ~Queue()=default;
      void enqueue(const T &value){
        q.push_back(value);
      }
      void dequeue(){
        if(q.empty()){
            throw underflow_error("the queue is empty");
        }
        else{
            q.erase(q.begin());
        }
      }
      T& front(){
        if(q.empty()) throw underflow_error("the queue is empty");
        else return &q[0];
      }
      const T& front() const {
        if(q.empty()) throw underflow_error("the queue is empty");
        else return q[0];
      }
      T& back(){
        if(q.empty()) throw underflow_error("the queue is empty");
        else return q.back();
      }
      const T& back() const{
         if(q.empty()) throw underflow_error("the queue is empty");
        else return q.back();
      }
      bool empty() const {
        return q.empty();
      }
      size_t size() const{
        return q.size();
      }
      bool operator==(const Queue<T>& other)const{
           return q==other.q;
      }
      bool operator!=(const Queue<T>& other) const{
        return q!=other.q;
      }
      void operator<<(ostream& os) const{
        for(const auto& it:q){
            os << it << " ";
        }
      }
};
