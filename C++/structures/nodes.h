#ifndef NODES_H
#define NODES_H

template <typename T>
struct NodeS{
    T data;
    NodeS* next = nullptr;
};

#endif