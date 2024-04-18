#pragma once
#include <iostream>
using namespace std;
#include "memory"

template<typename T>
struct Node {
    T data;
    shared_ptr<Node<T>> next;

    Node(const T& value) : data(value), next(nullptr) {}

};

template<typename T>
class SingleList {
private:
    shared_ptr<Node<T>> head;
    size_t size;
public:

    SingleList() :head(nullptr), size(0) {}

    // Методи вставки
    void pushFront(const T& value);
    void pushBack(const T& value);

    // Методи видалення
    void popFront();
    void popBack();
    //Доступ до елементів
    T& operator[](size_t index)const;

    //Додавання та віднімання за індексом
    void insertAt(size_t index, const T& value);
    void removeAt(size_t index);

};
