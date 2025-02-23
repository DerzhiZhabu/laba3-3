#include "../structures/stack.h"
#include <fstream>
#include <iostream>
#include <type_traits>
using namespace std;

template <typename T>
void Stack<T>::serializeBinary(const string &filename) const {
    ofstream outFile(filename, ios::binary);
    if (!outFile) {
        throw runtime_error("Unable to open file for binary serialization");
    }

    outFile.write(reinterpret_cast<const char *>(&length), sizeof(length));

    NodeS<T>* current = tail;
    while (current) {
        if constexpr (is_same_v<T, string>) {
            size_t strSize = current->data.size();
            outFile.write(reinterpret_cast<const char *>(&strSize), sizeof(strSize));
            outFile.write(current->data.data(), strSize);
        } else {
            outFile.write(reinterpret_cast<const char *>(&current->data), sizeof(T));
        }
        current = current->next;
    }

    outFile.close();
}

template <typename T>
void Stack<T>::deserializeBinary(const string &filename) {
    ifstream inFile(filename, ios::binary);
    if (!inFile) {
        throw runtime_error("Unable to open file for binary deserialization");
    }

    clear();
    int newLength = 0;
    inFile.read(reinterpret_cast<char *>(&newLength), sizeof(newLength));

    NodeS<T>* tempTail = nullptr;

    for (int i = 0; i < newLength && !inFile.eof(); ++i) {
        if constexpr (is_same_v<T, string>) {
            size_t strSize = 0;
            if (!inFile.read(reinterpret_cast<char *>(&strSize), sizeof(strSize))) break;
            string value(strSize, '\0');
            inFile.read(&value[0], strSize);

            NodeS<T>* newNode = new NodeS<T>{value, tempTail};
            tempTail = newNode;
        } else {
            T value;
            if (!inFile.read(reinterpret_cast<char *>(&value), sizeof(T))) break;

            NodeS<T>* newNode = new NodeS<T>{value, tempTail};
            tempTail = newNode;
        }
    }

    inFile.close();
    tail = tempTail;
    length = newLength;
}

template <typename T>
void Stack<T>::serializeText(const string &filename) const {
    ofstream outFile(filename);
    if (!outFile) {
        throw runtime_error("Unable to open file for text serialization");
    }

    NodeS<T>* current = tail;
    while (current) {
        if constexpr (is_same_v<T, string>) {
            outFile << current->data << "\n";
        } else {
            outFile << current->data << "\n";
        }
        current = current->next;
    }

    outFile.close();
}

template <typename T>
void Stack<T>::deserializeText(const string &filename) {
    ifstream inFile(filename);
    if (!inFile) {
        throw runtime_error("Unable to open file for text deserialization");
    }

    clear();
    NodeS<T>* tempTail = nullptr;
    string line;
    while (getline(inFile, line)) {
        if constexpr (is_same_v<T, string>) {
            if (!line.empty()) {
                NodeS<T>* newNode = new NodeS<T>{line, tempTail};
                tempTail = newNode;
            }
        } else {
            try {
                T value = stod(line);
                NodeS<T>* newNode = new NodeS<T>{value, tempTail};
                tempTail = newNode;
            } catch (...) {
                
            }
        }
    }

    inFile.close();

    
    tail = tempTail;
    length = 0;
    NodeS<T>* current = tail;
    while (current) {
        length++;
        current = current->next;
    }
}


int main() {
    Stack<string> stack;
    stack.push("First");
    stack.push("Second");
    stack.push("Third");

    cout << "Binary serialization" << endl;
    stack.serializeBinary("data.bin");

    Stack<string> binaryDser;
    binaryDser.deserializeBinary("data.bin");
    while (!binaryDser.isEmpty()) {
        cout << binaryDser.pop() << endl;
    }

    cout << "Text serialization" << endl;
    stack.serializeText("data.txt");

    Stack<string> textDser;
    textDser.deserializeText("data.txt");
    while (!textDser.isEmpty()) {
        cout << textDser.pop() << endl;
    }

    return 0;
}