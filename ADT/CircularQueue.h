#pragma once
#include <iostream>
#include "Double List.h"
using namespace std;

template<typename T>
class CircularQueue {
private:
    DoubleList<T> list;
    size_t capacity;  // ---- ����. ������� �����
public:
    CircularQueue() = default;

    CircularQueue(size_t capacity) : list(), capacity(capacity) {}
};