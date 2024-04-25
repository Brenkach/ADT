#pragma once
using namespace std;
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

    bool isEmpty()const {
        return currentSize == 0;
    }
    bool isFull()const {
        return currentSize == capacity;
    }

    void enqueue(T value) {
        if (isEmpty()) {
            front = rear = 0;
        }
        else {
            rear = (rear + 1) % capacity;// �������� ������ ������� ��� ���������
        }
        elements[rear] = value;
        currentSize++;
    }

    T dequeue() {
        if (isEmpty()) {
            throw underflow_error("Queue is empty");
        }
        T removedElement = elements[front];
        if (front == rear) {
            front = rear = -1;
        }
        else {
            front = (front + 1) % capacity;
        }
        currentSize--;
        return removedElement;
    }

    T peek() {
        if (isEmpty()) {
            throw out_of_range("Queue is empty");
        }
        return elements[front];
    }

    friend std::ostream& operator<<(std::ostream& os, const CircularQueueArray<T>& queue) {
        if (queue.isEmpty()) {
            os << "Queue is empty";
        }
        else {
            int i = queue.front;
            os << "Queue: ";
            while (true) {
                os << queue.elements[i] << " ";
                if (i == queue.rear) {
                    break;
                }
                i = (i + 1) % queue.capacity;
            }
        }
        return os;
    }
};