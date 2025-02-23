#ifndef TREE_H
#define TREE_H

#include <string>
#include <iomanip>
#include <cmath>
#include <type_traits>
#include <iostream>
#include "queue.h"
#include "list.h"

using namespace std;

template<typename T>
struct FullTree{

    private:

    struct NodeT{
        T data;
        NodeT* left = nullptr;
        NodeT* right = nullptr;
    };

    NodeT* root = nullptr;

    void insertHelper(NodeT* node, T& value){
        Queue<NodeT*> q;
        q.push(node);
        while(q.len() != 0){
            NodeT* current = q.pop();

            if (current->left == nullptr){
                current -> left = new NodeT{value, nullptr, nullptr};
                break;
            } else{
                q.push(current -> left);
            }

            if (current->right == nullptr){
                current -> right = new NodeT{value, nullptr, nullptr};
                break;
            } else{
                q.push(current -> right);
            }
        }

        q.clear();
    }

    bool checkNode(NodeT* node){
        if ((node -> right == nullptr && node -> left == nullptr)) return true;

        if ((node -> right == nullptr && node -> left != nullptr) || ((node -> right != nullptr && node -> left == nullptr))) return false;
        else{
            return (checkNode(node ->right) && checkNode(node -> left));
        }
    }

    int max_length(){
        int m = 0;
        Queue<NodeT*> q;
        q.push(root);
        while(q.len() != 0){
            NodeT* current = q.pop();
            string data = current->data;
            if (m < data.length()){
                m = data.length();
            }


            if (current->left != nullptr){
                q.push(current -> left);
            }

            if (current->right != nullptr){
                q.push(current -> right);
            }
        }

        q.clear();

        return m;
    }

    int getHeight(NodeT* node){
        int res = 0;
        while (node -> left != nullptr){
            node = node->left;
            res++;
        }
        return res;
    }

    void printTreeHelper(NodeT* node){
        int maxx = max_length();
         if (root == nullptr) {
            return;
        }

        Queue<NodeT*> q;
        q.push(root);
        int level = 0;
        int maxLevel = getHeight(root);

        while (q.len() != 0) {
            int size = q.len();
            int padding = (maxLevel - level) * maxx + 3 * (maxLevel - level);

            for (int i = 0; i < size; ++i) {
                NodeT* node = q.pop();

                if (node != nullptr) {
                    cout << setw(padding) << " ";
                    for (int i = 0; i < level; i++){
                        cout << ' ';
                    }
                    cout << node->data;
                    cout << setw(padding) << " ";
                    for (int i = 0; i < level; i++){
                        cout << ' ';
                    }

                    q.push(node->left);
                    q.push(node->right);
                } else {
                    cout << setw(padding) << "";
                    cout << " ";
                    cout << setw(padding) << "";
                }
            }

            cout << endl;
            ++level;
        }

        q.clear();
    }

    public:

    void serializeBinary(const std::string &filename) const;
    void deserializeBinary(const std::string &filename);

    void serializeText(const std::string &filename) const;
    void deserializeText(const std::string &filename);


    void insert(T value){
        if (root == nullptr) {
            root = new NodeT{value};
        } else {
            insertHelper(root, value);
        }
    }

    bool checkFull(){
        return checkNode(root);
    }

    void get(List<T>& res){
        Queue<NodeT*> q;
        q.push(root);
        while(q.length != 0){
            NodeT* current = q.pop();
            string data = current->data;
            res.push(data);


            if (current->left != nullptr){
                q.push(current -> left);
            }

            if (current->right != nullptr){
                q.push(current -> right);
            }
        }

        q.clear();
    }

    void print(){
        printTreeHelper(root);
    }

    

    void clear(){
        Queue<NodeT*> q;
        q.push(root);
        while(q.len() != 0){
            NodeT* current = q.pop();


            if (!(current->left == nullptr)){
                q.push(current -> left);
            }

            if (!(current->right == nullptr)){
                q.push(current -> right);
            }
            delete current;
        }

        q.clear();
        root = nullptr;
    }



};

#endif