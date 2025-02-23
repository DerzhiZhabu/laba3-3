#include "../structures/arr.h"
#include <fstream>
#include <iostream>
#include <limits>
using namespace std;

template <typename T>
void Array<T>::serializeBinary(const string &filename) const {
    ofstream outFile(filename, ios::binary);
    if (!outFile) {
        throw runtime_error("Unable to open file for binary serialization");
    }


    outFile.write(reinterpret_cast<const char *>(&length), sizeof(length));


    for (int i = 0; i < length; ++i) {
        if (head[i].state) {
            if constexpr (is_same_v<T, string>) {
                size_t strSize = head[i].value.size();
                outFile.write(reinterpret_cast<const char *>(&strSize), sizeof(strSize));
                outFile.write(head[i].value.data(), strSize);
            } else {
                outFile.write(reinterpret_cast<const char *>(&head[i].value), sizeof(T));
            }
        } else {

            if constexpr (is_same_v<T, string>) {
                size_t strSize = 0;
                outFile.write(reinterpret_cast<const char *>(&strSize), sizeof(strSize));
            } else {
                T emptyValue = T();
                outFile.write(reinterpret_cast<const char *>(&emptyValue), sizeof(T));
            }
        }
    }

    outFile.close();
}

template <typename T>
void Array<T>::deserializeBinary(const string &filename) {
    ifstream inFile(filename, ios::binary);
    if (!inFile) {
        throw runtime_error("Unable to open file for binary deserialization");
    }


    int newLength = 0;
    inFile.read(reinterpret_cast<char *>(&newLength), sizeof(newLength));


    resize(newLength);
    length = newLength;


    for (int i = 0; i < length; ++i) {
        if constexpr (is_same_v<T, string>) {
            size_t strSize = 0;
            inFile.read(reinterpret_cast<char *>(&strSize), sizeof(strSize));
            if (strSize > 0) {
                head[i].value.resize(strSize);
                inFile.read(&head[i].value[0], strSize);
                head[i].state = true;
            } else {
                head[i].state = false;
            }
        } else {
            inFile.read(reinterpret_cast<char *>(&head[i].value), sizeof(T));
            head[i].state = true;
        }
    }

    inFile.close();
}

template <typename T>
void Array<T>::serializeText(const string &filename) const {
    ofstream outFile(filename);
    if (!outFile) {
        throw runtime_error("Unable to open file for text serialization");
    }


    outFile << length << "\n";


    for (int i = 0; i < length; ++i) {
        if (head[i].state) {
            if constexpr (is_same_v<T, string>) {
                outFile << head[i].value << "\n";
            } else {
                outFile << head[i].value << "\n";
            }
        } else {
            outFile << "\n";
        }
    }

    outFile.close();
}

template <typename T>
void Array<T>::deserializeText(const string &filename) {
    ifstream inFile(filename);
    if (!inFile) {
        throw runtime_error("Unable to open file for text deserialization");
    }


    int newLength = 0;
    inFile >> newLength;
    inFile.ignore(numeric_limits<streamsize>::max(), '\n');


    resize(newLength);
    length = newLength;


    for (int i = 0; i < length; ++i) {
        string line;
        getline(inFile, line);

        if constexpr (is_same_v<T, string>) {
            if (!line.empty()) {
                head[i].value = line;
                head[i].state = true;
            } else {
                head[i].state = false;
            }
        } else {
            try {
                head[i].value = stod(line);
                head[i].state = true;
            } catch (...) {
                head[i].state = false;
            }
        }
    }

    inFile.close();
}


int main() {
    Array<string> arr;
    arr.push("First");
    arr.push("Second");
    arr.push("Third");

    cout << "Binary serialization" << endl;
    arr.serializeBinary("data.bin");

    Array<string> binaryDser;
    binaryDser.deserializeBinary("data.bin");
    binaryDser.print();

    cout << "Text serialization" << endl;
    arr.serializeText("data.txt");

    Array<string> textDser;
    textDser.deserializeText("data.txt");
    textDser.print();

    return 0;
}