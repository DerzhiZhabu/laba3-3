#include "../structures/tree.h"
#include <fstream>
#include <functional>
#include <iostream>
#include <type_traits>
using namespace std;

template <typename T>
void FullTree<T>::serializeBinary(const string &filename) const {
    if (!root) return; // Если дерево пустое, ничего не делаем

    ofstream outFile(filename, ios::binary);
    if (!outFile) {
        throw runtime_error("Unable to open file for binary serialization");
    }

    function<void(NodeT*)> serializeNode = [&](NodeT* node) {
        if (!node) {
            bool hasNode = false;
            outFile.write(reinterpret_cast<const char *>(&hasNode), sizeof(hasNode));
            return;
        }
        bool hasNode = true;
        outFile.write(reinterpret_cast<const char *>(&hasNode), sizeof(hasNode));

        if constexpr (is_same_v<T, string>) {
            size_t strSize = node->data.size();
            outFile.write(reinterpret_cast<const char *>(&strSize), sizeof(strSize));
            outFile.write(node->data.data(), strSize);
        } else {
            outFile.write(reinterpret_cast<const char *>(&node->data), sizeof(T));
        }

        serializeNode(node->left);
        serializeNode(node->right);
    };

    serializeNode(root);
    outFile.close();
}

template <typename T>
void FullTree<T>::deserializeBinary(const string &filename) {
    ifstream inFile(filename, ios::binary);
    if (!inFile) {
        throw runtime_error("Unable to open file for binary deserialization");
    }

    function<NodeT*()> deserializeNode = [&]() -> NodeT* {
        bool hasNode;
        if (!inFile.read(reinterpret_cast<char *>(&hasNode), sizeof(hasNode))) {
            return nullptr;
        }

        if (!hasNode) {
            return nullptr;
        }

        NodeT* node = new NodeT;

        if constexpr (is_same_v<T, string>) {
            size_t strSize = 0;
            if (!inFile.read(reinterpret_cast<char *>(&strSize), sizeof(strSize))) {
                delete node;
                return nullptr;
            }
            node->data.resize(strSize);
            if (!inFile.read(&node->data[0], strSize)) {
                delete node;
                return nullptr;
            }
        } else {
            if (!inFile.read(reinterpret_cast<char *>(&node->data), sizeof(T))) {
                delete node;
                return nullptr;
            }
        }

        node->left = deserializeNode();
        node->right = deserializeNode();
        return node;
    };
    root = deserializeNode();
    inFile.close();
}

template <typename T>
void FullTree<T>::serializeText(const string &filename) const {
    if (!root) return;

    ofstream outFile(filename);
    if (!outFile) {
        throw runtime_error("Unable to open file for text serialization");
    }

    function<void(NodeT*)> serializeNode = [&](NodeT* node) {
        if (!node) {
            outFile << "# ";
            return;
        }
        if constexpr (is_same_v<T, string>) {
            outFile << '"' << node->data << "\" ";
        } else {
            outFile << node->data << " ";
        }
        serializeNode(node->left);
        serializeNode(node->right);
    };

    serializeNode(root);
    outFile.close();
}

template <typename T>
void FullTree<T>::deserializeText(const string &filename) {
    ifstream inFile(filename);
    if (!inFile) {
        throw runtime_error("Unable to open file for text deserialization");
    }

    function<NodeT*()> deserializeNode = [&]() -> NodeT* {
        string token;
        if (!(inFile >> token)) {
            return nullptr;
        }

        if (token == "#") {
            return nullptr;
        }

        NodeT* node = new NodeT;

        if constexpr (is_same_v<T, string>) {
            if (token.front() == '"' && token.back() == '"') {
                token = token.substr(1, token.size() - 2);
            }
            node->data = token;
        } else {
            try {
                node->data = stod(token);
            } catch (...) {
                delete node;
                return nullptr;
            }
        }

        node->left = deserializeNode();
        node->right = deserializeNode();
        return node;
    };
    root = deserializeNode();
    inFile.close();
}


int main() {
    FullTree<string> tree;
    tree.insert("Root");
    tree.insert("Left");
    tree.insert("Right");
    tree.insert("LeftLeft");
    tree.insert("LeftRight");

    cout << "Binary serialization" << endl;
    tree.serializeBinary("data.bin");

    FullTree<string> binaryDser;
    binaryDser.deserializeBinary("data.bin");
    binaryDser.print();

    cout << "Text serialization" << endl;
    tree.serializeText("data.txt");

    FullTree<string> textDser;
    textDser.deserializeText("data.txt");
    textDser.print();

    return 0;
}