#pragma once
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
};
