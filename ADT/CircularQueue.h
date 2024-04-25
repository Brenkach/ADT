#pragma once
#include <iostream>
#include "Double List.h"

template<typename T>
class CircularQueue {
private:
    DoubleList<T> list;
    size_t capacity;  // ---- Макс. місткість черги
public:
    CircularQueue() = default;

    CircularQueue(size_t capacity) : list(), capacity(capacity) {}
};