#pragma once
#include "Double List.h"
#include <iostream>
const int SIZE = 5;


template<typename T>
class Queue {
private:
    DoubleList<T> list;
    size_t capacity;
public:
    Queue() = default;
    Queue(const Queue& other) = default;
    Queue(Queue&& other) = default;

    ~Queue() = default;

    Queue& operator=(const Queue& other) = default;
    Queue& operator=(Queue&& other) noexcept = default;

};