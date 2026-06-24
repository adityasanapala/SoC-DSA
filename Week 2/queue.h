#ifndef QUEUE_H
#define QUEUE_H
#include <vector>
#include <stdexcept>
#include <iostream>

template <typename T>

class Queue{
    private:
    std::vector<T> queue;
    
    Queue() = default;

    void enqueue(const T& value){
        queue.push_back(value);
    }

    bool empty() const{
        return queue.empty();
    }

    void dequeue(){
        if(!queue.empty()){
            queue.erase(queue.begin());
        }
        else{
            throw std::underflow_error("The Queue is empty");
        }
    }

    T& front(){
        return queue.begin();
    }
    const T& front() const{
        return queue.begin();
    }

    T& back(){
        return queue.back();
    }
    const T& back() const{
        return queue.back();
    }

    std::size_t size() const{
        return queue.size();
    }

    bool operator==(const Queue& other) const {
        return queue == other.queue;
    }

    bool operator!=(const Queue& other) const {
        return queue != other.queue;
    }

    friend std::ostream& operator<<(std::ostream& os, const Queue<T>& q) {
        os << "[";

        for (int i = static_cast<int>(q.queue.size()) - 1; i >= 0; --i) {
            os << q.queue[i];
            if (i > 0) os << " ";
        }

        os << "]";

        return os;
    }
};

#endif
