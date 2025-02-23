#include "../structures/list.h"
#include <fstream>
#include <iostream>
#include <type_traits>
using namespace std;

template <typename T>
void List<T>::serializeBinary(const string &filename) const {
    ofstream outFile(filename, ios::binary);
    if (!outFile) {
        throw runtime_error("Unable to open file for binary serialization");
    }

    
    outFile.write(reinterpret_cast<const char *>(&length), sizeof(length));

    
    NodeD<T>* current = head->next;
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
void List<T>::deserializeBinary(const string &filename) {
    ifstream inFile(filename, ios::binary);
    if (!inFile) {
        throw runtime_error("Unable to open file for binary deserialization");
    }

    
    clear();

    
    head = new NodeD<T>;
    tail = head;

    
    int newLength = 0;
    inFile.read(reinterpret_cast<char *>(&newLength), sizeof(newLength));

    
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
void List<T>::serializeText(const string &filename) const {
    ofstream outFile(filename);
    if (!outFile) {
        throw runtime_error("Unable to open file for text serialization");
    }

    
    NodeD<T>* current = head->next;
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
void List<T>::deserializeText(const string &filename) {
    ifstream inFile(filename);
    if (!inFile) {
        throw runtime_error("Unable to open file for text deserialization");
    }

    
    clear();

    
    head = new NodeD<T>;
    tail = head;

    
    string line;
    while (getline(inFile, line)) {
        if constexpr (is_same_v<T, string>) {
            if (!line.empty()) { 
                push(line);
            }
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
    List<string> list;
    list.push("First");
    list.push("Second");
    list.push("Third");

    cout << "Binary serialization" << endl;
    list.serializeBinary("data.bin");

    List<string> binaryDser;
    binaryDser.deserializeBinary("data.bin");
    for (int i = 0; i < binaryDser.len(); ++i) {
        cout << binaryDser[i] << endl;
    }

    cout << "Text serialization" << endl;
    list.serializeText("data.txt");

    List<string> textDser;
    textDser.deserializeText("data.txt");
    for (int i = 0; i < textDser.len(); ++i) {
        cout << textDser[i] << endl;
    }

    return 0;
}