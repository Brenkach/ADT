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
};