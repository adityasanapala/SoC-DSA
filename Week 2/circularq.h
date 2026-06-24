#ifndef CIRCULARQ_H
#define CIRCULARQ_H
#include <vector>
#include <stdexcept>
#include <iostream>

template <typename T>

class CircularQueue {
private:
    std::vector<T> queue;
    int head;
    int capacity;
    int currentSize;

public:
    // Initialize the queue with a fixed capacity
    CircularQueue(int size) {
        capacity = size;
        queue.resize(capacity);
        head = 0;
        currentSize = 0;
    }

    // Check if the queue is full
    bool isFull() {
        return currentSize == capacity;
    }

    // Check if the queue is empty
    bool isEmpty() {
        return currentSize == 0;
    }

    // Add an item to the rear of the queue
    void enqueue(int value) {
        if (isFull()) {
            throw std::overflow_error("Queue is full");
        }
        else{
            int rear = (head + currentSize) % capacity;
            queue[rear] = value;
            currentSize++;
        }

    }

    // Remove an item from the front of the queue
    void dequeue() {
        if (isEmpty()) {
            throw std::underflow_error("Queue is empty");
        }
        // Advance the head circularly
        else{
            head = (head + 1) % capacity;
            currentSize--;
        }
    }

    // Get the front element
    int getFront() {
        if (isEmpty()) return -1;
        return queue[head];
    }

    // Get the rear element
    int getRear() {
        if (isEmpty()) return -1;
        int rear = (head + currentSize - 1) % capacity;
        return queue[rear];
    }

    bool operator==(const CircularQueue& other) const {
        return queue == other.queue;
    }

    bool operator!=(const CircularQueue& other) const {
        return queue != other.queue;
    }

    

};

#endif