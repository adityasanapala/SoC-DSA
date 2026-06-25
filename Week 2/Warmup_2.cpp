#include <iostream>
#include <deque>
#include <stdexcept>

template <typename T>
class Queue {
private:
    std::deque<T> data;

public:
    Queue() = default;
    ~Queue() = default;

    void enqueue(const T &value) {
        data.push_back(value);
    }

    void dequeue() {
        if (empty())
            throw std::underflow_error("Queue is empty");
        data.pop_front();
    }

    T &front() {
        if (empty())
            throw std::underflow_error("Queue is empty");
        return data.front();
    }

    const T &front() const {
        if (empty())
            throw std::underflow_error("Queue is empty");
        return data.front();
    }

    T &back() {
        if (empty())
            throw std::underflow_error("Queue is empty");
        return data.back();
    }

    const T &back() const {
        if (empty())
            throw std::underflow_error("Queue is empty");
        return data.back();
    }

    bool empty() const {
        return data.empty();
    }

    std::size_t size() const {
        return data.size();
    }

    bool operator==(const Queue &other) const {
        return data == other.data;
    }

    bool operator!=(const Queue &other) const {
        return !(*this == other);
    }

    friend std::ostream &operator<<(std::ostream &os, const Queue &q) {
        os << "[";
        for (size_t i = 0; i < q.data.size(); i++) {
            os << q.data[i];
            if (i + 1 != q.data.size())
                os << ", ";
        }
        os << "]";
        return os;
    }
};