package main

import (
    "fmt"
    "my_project/serialization"
    "my_project/tree"
)

func main() {
    // Создание дерева
    t := &tree.FullTree{}
    t.Insert("ROOT")
    t.Insert("LEFT")
    t.Insert("RIGHT")

    // Вывод содержимого дерева перед сериализацией
    fmt.Println("Original Tree Data:", t.Get())

    // Бинарная сериализация
    fmt.Println("\nBinary Serialization")
    if err := serialization.SerializeBinary(t, "data.bin"); err != nil {
        fmt.Println("Error during binary serialization:", err)
    }

    // Бинарная десериализация
    deserializedTree := &tree.FullTree{}
    if err := serialization.DeserializeBinary(deserializedTree, "data.bin"); err != nil {
        fmt.Println("Error during binary deserialization:", err)
    }
    fmt.Println("Deserialized Binary Tree Data:", deserializedTree.Get())

    // Текстовая сериализация
    fmt.Println("\nText Serialization")
    if err := serialization.SerializeText(t, "data.txt"); err != nil {
        fmt.Println("Error during text serialization:", err)
    }

    // Текстовая десериализация
    deserializedTextTree := &tree.FullTree{}
    if err := serialization.DeserializeText(deserializedTextTree, "data.txt"); err != nil {
        fmt.Println("Error during text deserialization:", err)
    }
    fmt.Println("Deserialized Text Tree Data:", deserializedTextTree.Get())
}