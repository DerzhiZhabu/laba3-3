#ifndef ARR_H
#define ARR_H

#include <string>
#include <iomanip>
#include <cmath>
#include <type_traits>
#include <iostream>

using namespace std;

template <typename T>
class Array{

    private:

    struct Node{
        T value;
        bool state = false;
    };

    int next_push = 0;
    int size = 8;
    int length = size;
    int last_used = 0;
    Node* head = new Node[size];

    void resize(int neww){
        Node* old_arr = head;
        head = new Node[neww];
        for(int i = 0; i < size; i++){
            if (old_arr[i].state){
                head[i] = old_arr[i];
            }
        }
        size = neww;
        length = size;
    }

    void check(){
        if (next_push == size){
            resize(size * 2);
        }
    }

    public:

    void serializeBinary(const std::string &filename) const;
    void deserializeBinary(const std::string &filename);

    void serializeText(const std::string &filename) const;
    void deserializeText(const std::string &filename);

    void push(T data){
        head[next_push].value = data;
        head[next_push].state = true;
        next_push++;
        check();
    }

    void set(T data, int index){
        if (index >= length) throw runtime_error("Out of range");
        head[index].value = data;
        head[index].state = true;
        if(index >= next_push) next_push = index + 1;
        check();
    }

    Node get(int index){
        if (index >= length) throw runtime_error("Out of range");

        return head[index];
    }

    T operator[](int index){
        if (index >= length) throw runtime_error("Out of range");
        if (!head[index].state) throw runtime_error("No value");
        return head[index].value;
    }

    void del(int index){
        if (index >= length) throw runtime_error("Out of range");
        if (!head[index].state) throw runtime_error("No value");
        head[index].state = false;
    }

    int find(T data){
        for (int i = 0; i < length; i++){
            if(head[i].value == data && head[i].state){
                return i;
            }
        }

        return -1;
    }

    void remove(T data){
        int index = find(data);
        if  (index == -1) throw runtime_error("No value");

        head[index].state = false;
    }

    ~Array(){
        delete[] head;
    }

    int len(){
        return length;
    }

    void print(){
        for (int i = 0; i < length; i++){
            if (head[i].state) cout << head[i].value << ' ';
        }
        cout << endl;
    }

};

#endif