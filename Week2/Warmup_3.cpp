template <typename T>
class CircularQueue {
private:
    std::vector<T> arr;
    int head;
    int tail;
    int count;
    int capacity;

public:
    CircularQueue(int cap)
        : arr(cap), head(0), tail(0), count(0), capacity(cap) {}

    void enqueue(const T &value) {
        if (count == capacity)
            throw std::overflow_error("Queue Full");

        arr[tail] = value;
        tail = (tail + 1) % capacity;
        count++;
    }

    void dequeue() {
        if (count == 0)
            throw std::underflow_error("Queue Empty");

        head = (head + 1) % capacity;
        count--;
    }

    T &front() {
        if (count == 0)
            throw std::underflow_error("Queue Empty");

        return arr[head];
    }

    bool empty() const {
        return count == 0;
    }
};