#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Stack {
 private :
    vector<T> st;
 public :
    Stack() = default;
    ~Stack() = default;
    void push(const T& value) {
        st.push_back(value);
    }
    void pop() {
        if(st.empty()) {
            throw underflow_error("Stack underflow");
        }
        st.pop_back();
    }
    T& top() {
        if(st.empty()) {
            throw underflow_error("Stack underflow");
        }
        return st.back();
    }
    const T& top() const {
        if(st.empty()) {
            throw underflow_error("Stack underflow");
        }
        return st.back();
    }
    bool empty() const {
        return st.empty();
    }
    size_t size() const {
        return st.size();
    }
    bool operator==(const Stack<T>& other) const {
        return st == other.st;
    }
    bool operator!=(const Stack<T>& other) const {
        return st != other.st;
    }
    void operator<<(ostream& os) const {
        for(const auto& elem : st) {
            os << elem << " ";
        }
    }

};