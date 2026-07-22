#ifndef STACK_H
#define STACK_H
#include <vector>
#include <stdexcept>
#include <iostream>


template <typename T>

class Stack {
    private:
    std::vector<T> stack;

    public:
    Stack() = default;
    Stack(std::initializer_list<T> list){
        for(auto item : list){
            stack.push_back(item);
        }

    }
    void push(const T& value) {
        stack.push_back(value);
    }
    void pop() {
        if (!stack.empty()) {
            stack.pop_back();
        }
        else{
            throw std::underflow_error("Stack is empty");
        }
    }
    T& top(){
        if(!stack.empty()){
            return stack.back();
        }
        else{
            throw std::underflow_error("Stack is empty");
        } 
    }
    const T& top() const{
        if (!stack.empty()) {
            return stack.back();
        }
        else {
            throw std::underflow_error("Stack is empty");
        }
    }
    bool empty() const {
        return stack.empty();
    }
    std::size_t size() const {
        return stack.size();
    }
    bool operator==(const Stack& other) const {
        return stack == other.stack;
    }

    bool operator!=(const Stack& other) const {
        return stack != other.stack;
    }

    friend std::ostream& operator<<(std::ostream& os, const Stack<T>& s) {
        os << "[";

        for (int i = static_cast<int>(s.stack.size()) - 1; i >= 0; --i) {
            os << s.stack[i];
            if (i > 0) os << " ";
        }

        os << "]";

        return os;
    }

};

#endif