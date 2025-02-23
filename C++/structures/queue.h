#ifndef QUEUE_H
#define QUEUE_H

#include <string>
#include <iomanip>
#include <cmath>
#include <type_traits>
#include "nodes.h"

using namespace std;


template <typename T>
class Queue{

    private:

    int length = 0;
    NodeS<T>* head = new NodeS<T>;

    public:

    void push(T data){
        NodeS<T>* new_node = head;
        while((new_node -> next) != nullptr){
            new_node = new_node -> next;
        }
        new_node->next = new NodeS<T>{data, nullptr};
        length += 1;
    }

    void serializeBinary(const std::string &filename) const;
    void deserializeBinary(const std::string &filename);

    void serializeText(const std::string &filename) const;
    void deserializeText(const std::string &filename);

    bool isEmpty(){
        return length==0;
    }

    T front(){
        return head->next->data;
    }

    T pop(){
        if (length == 0) throw runtime_error("Stack is empty");

        NodeS<T>* new_node = head->next;
        head->next = new_node->next;
        length -= 1;

        T value = new_node->data;
        
        delete new_node;
        return value;
    }

    void clear(){
        while (length != 0){
            pop();
        }
    }

    int len(){
        return length;
    }
};

#endif