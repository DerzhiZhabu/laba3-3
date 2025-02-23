#include "../structures/queue.h"
#include <fstream>
#include <iostream>
#include <type_traits>
using namespace std;

template <typename T>
void Queue<T>::serializeBinary(const string &filename) const {
    ofstream outFile(filename, ios::binary);
    if (!outFile) {
        throw runtime_error("Unable to open file for binary serialization");
    }

    
    outFile.write(reinterpret_cast<const char *>(&length), sizeof(length));

    
    NodeS<T>* current = head->next;
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
void Queue<T>::deserializeBinary(const string &filename) {
    ifstream inFile(filename, ios::binary);
    if (!inFile) {
        throw runtime_error("Unable to open file for binary deserialization");
    }
    
    int newLength = 0;
    inFile.read(reinterpret_cast<char *>(&newLength), sizeof(newLength));

    
    clear();

    
    for (int i = 0; i < newLength; ++i) {
        if constexpr (is_same_v<T, string>) {
            size_t strSize = 0;
            inFile.read(reinterpret_cast<char *>(&strSize), sizeof(strSize));
            string value(strSize, '\0');
            inFile.read(&value[0], strSize);
            push(value);
        } else {
            T value;
            inFile.read(reinterpret_cast<char *>(&value), sizeof(T));
            push(value);
        }
    }

    inFile.close();
}

template <typename T>
void Queue<T>::serializeText(const string &filename) const {
    ofstream outFile(filename);
    if (!outFile) {
        throw runtime_error("Unable to open file for text serialization");
    }

    
    NodeS<T>* current = head->next;
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
void Queue<T>::deserializeText(const string &filename) {
    ifstream inFile(filename);
    if (!inFile) {
        throw runtime_error("Unable to open file for text deserialization");
    }

    clear();

    
    string line;
    while (getline(inFile, line)) {
        if constexpr (is_same_v<T, string>) {
            push(line);
        } else {
            try {
                T value = stod(line); 
                push(value);
            } catch (...) {
            }
        }
    }

    inFile.close();
}


int main() {
    Queue<string> queue;
    queue.push("First");
    queue.push("Second");
    queue.push("Third");

    cout << "Binary serialization" << endl;
    queue.serializeBinary("data.bin");

    Queue<string> binaryDser;
    binaryDser.deserializeBinary("data.bin");
    while (!binaryDser.isEmpty()) {
        cout << binaryDser.front() << endl;
        binaryDser.pop();
    }

    cout << "Text serialization" << endl;
    queue.serializeText("data.txt");

    Queue<string> textDser;
    textDser.deserializeText("data.txt");
    while (!textDser.isEmpty()) {
        cout << textDser.front() << endl;
        textDser.pop();
    }

    return 0;
}