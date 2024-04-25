#pragma once
#include<iostream>
#include "Double List.h"
using namespace std;

template<typename T>
class Stack {
private:
    DoubleList<T> list;

public:
    Stack() : list() {}

    bool IsEmpty() const {
        return list.isEmpty();
    }

    T Peek()const {
        if (list.isEmpty()) {
            throw out_of_range("Stack is empty");
        }
        return list[Size() - 1];
    }

    void Push(const T& value) {
        list.pushBack(value);
    }

    T Pop() {
        if (IsEmpty()) {
            throw underflow_error("Stack is empty");
        }
        T value = list[Size() - 1];
        list.popBack();
        return value;
    }

    size_t Size()const {
        return list.Size();
    }

    friend ostream& operator<<(ostream& os, const Stack<T>& stack) {
        os << stack.list;
        return os;
    }
};