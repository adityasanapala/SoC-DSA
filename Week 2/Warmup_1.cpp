#include <iostream>
#include <vector>
#include <stdexcept>
#include <initializer_list>

template <typename T>
class Stack {
private:
    std::vector<T> data;

public:
    Stack() = default;

    Stack(std::initializer_list<T> list) {
        for (const auto &x : list)
            data.push_back(x);
    }

    ~Stack() = default;

    void push(const T &value) {
        data.push_back(value);
    }

    void pop() {
        if (empty())
            throw std::underflow_error("Stack is empty");
        data.pop_back();
    }

    T &top() {
        if (empty())
            throw std::underflow_error("Stack is empty");
        return data.back();
    }

    const T &top() const {
        if (empty())
            throw std::underflow_error("Stack is empty");
        return data.back();
    }

    bool empty() const {
        return data.empty();
    }

    std::size_t size() const {
        return data.size();
    }

    bool operator==(const Stack &other) const {
        return data == other.data;
    }

    bool operator!=(const Stack &other) const {
        return !(*this == other);
    }

    friend std::ostream &operator<<(std::ostream &os, const Stack &s) {
        os << "[";
        for (int i = s.data.size() - 1; i >= 0; i--) {
            os << s.data[i];
            if (i != 0)
                os << ", ";
        }
        os << "]";
        return os;
    }
};