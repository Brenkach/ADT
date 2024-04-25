#pragma once
#include<iostream>
#include "Double List.h"

template<typename T>
class Stack {
private:
    DoubleList<T> list;

public:
    Stack() : list() {}
};