/* 
name: mohammad burair
roll number: 24k 0775
section: bcs-1c
date: 11-05-2025
description: queue class with overflow and underflow exception handling
*/

#include <iostream>
#include <stdexcept>

using namespace std;

class queueoverflowexception : public exception {};
class queueunderflowexception : public exception {};

template <typename t>
class queue {
private:
    t* data;
    int capacity;
    int front;
    int rear;
    int count;

public:
    queue(int size) : capacity(size), front(0), rear(-1), count(0) {
        data = new t[capacity];
    }

    ~queue() {
        delete[] data;
    }

    void enqueue(const t& item) {
        if (isfull()) {
            throw queueoverflowexception();
        }
        rear = (rear + 1) % capacity;
        data[rear] = item;
        count++;
    }

    t dequeue() {
        if (isempty()) {
            throw queueunderflowexception();
        }
        t item = data[front];
        front = (front + 1) % capacity;
        count--;
        return item;
    }

    bool isempty() const {
        return count == 0;
    }

    bool isfull() const {
        return count == capacity;
    }
};

int main() {
    try {
        queue<int> q(3);
        q.enqueue(1);
        q.enqueue(2);
        q.enqueue(3);
        cout << "attempting to enqueue to a full queue" << endl;
        q.enqueue(4);
    }
    catch (const queueoverflowexception& e) {
        cerr << "caught queueoverflowexception - what(): " << e.what() << endl;
    }

    try {
        queue<int> q(3);
        cout << "attempting to dequeue from an empty queue" << endl;
        q.dequeue();
    }
    catch (const queueunderflowexception& e) {
        cerr << "caught queueunderflowexception - what(): " << e.what() << endl;
    }

    return 0;
}
