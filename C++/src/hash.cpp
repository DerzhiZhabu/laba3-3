#include <fstream>
#include <iostream>
#include <sstream>
#include <type_traits>
#include "../structures/hash.h"

using namespace std;

template <typename T>
void HashTable<T>::serializeBinary(const string &filename) const {
    ofstream outFile(filename, ios::binary);
    if (!outFile) {
        throw runtime_error("Unable to open file for binary serialization");
    }

    outFile.write(reinterpret_cast<const char *>(&size), sizeof(size));


    for (int i = 0; i < size; ++i) {
        if (arr[i].state && !arr[i].deleted) {

            size_t keySize = arr[i].key.size();
            outFile.write(reinterpret_cast<const char *>(&keySize), sizeof(keySize));
            outFile.write(arr[i].key.c_str(), keySize);
            if constexpr (is_same_v<T, string>) {
                size_t valueSize = arr[i].value.size();
                outFile.write(reinterpret_cast<const char *>(&valueSize), sizeof(valueSize));
                outFile.write(arr[i].value.c_str(), valueSize);
            } else {
                outFile.write(reinterpret_cast<const char *>(&arr[i].value), sizeof(T));
            }
        }
    }

    outFile.close();
}

template <typename T>
void HashTable<T>::deserializeBinary(const string &filename) {
    ifstream inFile(filename, ios::binary);
    if (!inFile) {
        throw runtime_error("Unable to open file for binary deserialization");
    }

    int newSize;
    inFile.read(reinterpret_cast<char *>(&newSize), sizeof(newSize));
    NodeH<T> *oldArr = arr;
    size = newSize;
    arr = new NodeH<T>[size];

    for (int i = 0; i < size; ++i) {
        arr[i].state = false;
        arr[i].deleted = false;
    }

    delete[] oldArr;
    while (inFile.peek() != EOF) {
        size_t keySize;
        inFile.read(reinterpret_cast<char *>(&keySize), sizeof(keySize));
        string key(keySize, '\0');
        inFile.read(&key[0], keySize);

        T value;
        if constexpr (is_same_v<T, string>) {
            size_t valueSize;
            inFile.read(reinterpret_cast<char *>(&valueSize), sizeof(valueSize));
            value.resize(valueSize);
            inFile.read(&value[0], valueSize);
        } else {
            inFile.read(reinterpret_cast<char *>(&value), sizeof(T));
        }

        try {
            Add(key, value);
        } catch (const runtime_error &) {
        }
    }

    inFile.close();
}

template <typename T>
void HashTable<T>::serializeText(const string &filename) const {
    ofstream outFile(filename);
    if (!outFile) {
        throw runtime_error("Unable to open file for text serialization");
    }

    for (int i = 0; i < size; ++i) {
        if (arr[i].state && !arr[i].deleted) {
            outFile << arr[i].key << "=";
            if constexpr (is_same_v<T, string>) {
                outFile << arr[i].value;
            } else {
                outFile << arr[i].value;
            }
            outFile << "\n";
        }
    }

    outFile.close();
}

template <typename T>
void HashTable<T>::deserializeText(const string &filename) {
    ifstream inFile(filename);
    if (!inFile) {
        throw runtime_error("Unable to open file for text deserialization");
    }

    string line;
    while (getline(inFile, line)) {
        istringstream stream(line);
        string key;
        T value;

        if (getline(stream, key, '=') && (stream >> value)) {
            try {
                Add(key, value);
            } catch (const runtime_error &) {
            }
        }
    }

    inFile.close();
}
int main() {
    HashTable<string> ht;
    ht.Add("key1", "First");
    ht.Add("key2", "Second");
    ht.Add("key3", "Third");

    cout << "Binary serialization" << endl;
    ht.serializeBinary("data.bin");

    HashTable<string> binaryDser;
    binaryDser.deserializeBinary("data.bin");
    cout << binaryDser.Get("key1") << endl;
    cout << binaryDser.Get("key2") << endl;
    cout << binaryDser.Get("key3") << endl;

    cout << "Text serialization" << endl;
    ht.serializeText("data.txt");

    HashTable<string> textDser;
    textDser.deserializeText("data.txt");
    cout << textDser.Get("key1") << endl;
    cout << textDser.Get("key2") << endl;
    cout << textDser.Get("key3") << endl;

    return 0;
}