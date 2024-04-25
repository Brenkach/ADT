#pragma once
#include <iostream>
using namespace std;

template<typename T>
class StackArray {
private:
    T* elements;
    size_t capacity;
    size_t top;

    void Resize(size_t newCapacity) {
        T* newItems = new T[newCapacity];
        for (size_t i = 0; i < top; ++i) {
            newItems[i] = elements[i];
        }
        delete[] elements;
        elements = newItems;
        capacity = newCapacity;
    }       // Зміна розміра масиву
public:

    StackArray(size_t initialCapacity = 10) :capacity(initialCapacity), top(0) {
        elements = new T[capacity];
    }
    ~StackArray() {
        delete[] elements;
    }
    bool IsEmpty() const {
        return top == 0;
    }

    T Peek() const {
        if (IsEmpty()) {
            throw out_of_range("Stack is empty");
        }
        return elements[top - 1];
    }


    void Push(const T& value) {
        if (top == capacity) {
            Resize(capacity * 2); // Подвоюємо розмір масиву, якщо стек повний
        }
        elements[top++] = value;
    }

    T Pop() {
        if (IsEmpty()) {
            throw underflow_error("Stack is empty");
        }
        T value = elements[--top];
        if (top > 0 && top == capacity / 4) {
            Resize(capacity / 2); // Зменшуємо розмір масиву, якщо стек наполовину порожній
        }
        return value;
    }

    size_t Size() const {
        return top;
    }

    friend ostream& operator<<(ostream& os, const StackArray<T>& stack) {
        for (size_t i = 0; i < stack.top; ++i) {
            os << stack.elements[i] << " ";
        }
        return os;
    }


};