#pragma once
#include <iostream>

template<typename T>
class StackArray {
private:
    T* elements;
    size_t capacity;
    size_t top;
public:

    StackArray(size_t initialCapacity = 10) :capacity(initialCapacity), top(0) {
        elements = new T[capacity];
    }
    ~StackArray() {
        delete[] elements;
    }

};