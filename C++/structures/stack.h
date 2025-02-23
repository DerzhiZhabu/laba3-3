#ifndef STACK_H
#define STACK_H

#include <string>
#include <iomanip>
#include <cmath>
#include <type_traits>
#include "nodes.h"

using namespace std;

template <typename T>
class Stack{
    private:

    int length = 0;
    NodeS<T>* tail = nullptr;

    public:

    bool isEmpty(){
        return length==0;
    }

    void serializeBinary(const std::string &filename) const;
    void deserializeBinary(const std::string &filename);

    void serializeText(const std::string &filename) const;
    void deserializeText(const std::string &filename);

    void push(T data){
        NodeS<T>* new_node = new NodeS<T>{data, tail};
        tail = new_node;
        length += 1;
    }

    T pop(){
        if (length == 0) throw runtime_error("Stack is empty");

        NodeS<T>* new_node = tail->next;
        length -= 1;

        T value = tail->data;
        
        delete tail;
        tail = new_node;
        return value;
    }

    int len(){
        return length;
    }

    void clear(){
        while (length != 0){
            pop();
        }
    }
};

#endif