#pragma once
using namespace std;
template<typename T>
class QueueArray {
private:
    T element[SIZE];
    int front;
    int rear;
public:
    QueueArray() {
        front = -1;
        rear = -1;
    }


    bool isEmpty() const {
        return front == -1 && rear == -1;
    }
    bool isFull()const {
        return rear == SIZE - 1;
    }
    void enqueue(T value) {
        if (isFull()) {
            throw overflow_error("Queue is full");
        }
        if (isEmpty()) {
            front = rear = 0;
        }
        else {
            rear++;
        }
        element[rear] = value;
        //        cout<<"Enqueued: "<<value<<endl;
    }
    T dequeue() {
        if (isEmpty()) {
            throw underflow_error("Queue is empty");
        }
        T removedElem = element[front];
        if (front == rear) {
            front = rear = -1;
        }
        else {
            front++;
        }
        //        cout << "Dequeued: " << removedElem << endl;
        return removedElem;
    }
    T peek() {
        if (isEmpty()) {
            throw out_of_range("Queue is empty");
        }
        return element[front];
    }

    friend ostream& operator<<(ostream& os, const QueueArray<T>& queue) {
        if (queue.isEmpty()) {
            os << "Queue is empty";
        }
        else {
            int i = queue.front;
            while (i != queue.rear) {
                os << queue.element[i] << " ";
                i = (i + 1) % SIZE;
            }
            os << queue.element[i];
        }
        return os;
    }
};
