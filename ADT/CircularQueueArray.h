#pragma once
template<typename T>
class CircularQueueArray {
private:
    //    shared_ptr<T>elements;
    T* elements;
    int front;
    int rear;
    int capacity;
    int currentSize;
public:
    CircularQueueArray(int size = 10) :capacity(size), front(-1), rear(-1), currentSize(0) {
        //        elements = make_shared<T>(capacity);
        elements = new T[capacity];
    }
    ~CircularQueueArray() {
        delete[] elements;
    }
};