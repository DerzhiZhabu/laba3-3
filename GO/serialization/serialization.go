package serialization

import (
    "bufio"
    "encoding/binary"
    "errors"
    "io"
    "os"

    "my_project/tree"
)

// SerializeBinary serializes the tree into a binary file.
func SerializeBinary(tree *tree.FullTree, filename string) error {
    file, err := os.Create(filename)
    if err != nil {
        return err
    }
    defer file.Close()

    writer := bufio.NewWriter(file)
    data := tree.Get() // Получаем все элементы дерева в порядке обхода
    for _, value := range data {
        valueSize := uint32(len(value))
        if err := binary.Write(writer, binary.LittleEndian, valueSize); err != nil {
            return err
        }
        if _, err := writer.WriteString(value); err != nil {
            return err
        }
    }
    return writer.Flush()
}

// DeserializeBinary deserializes the binary file into the tree.
func DeserializeBinary(tree *tree.FullTree, filename string) error {
    file, err := os.Open(filename)
    if err != nil {
        return err
    }
    defer file.Close()

    reader := bufio.NewReader(file)
    tree.Clear() // Очищаем дерево перед десериализацией
    for {
        var valueSize uint32
        if err := binary.Read(reader, binary.LittleEndian, &valueSize); err != nil {
            if errors.Is(err, io.EOF) {
                break
            }
            return err
        }
        value := make([]byte, valueSize)
        if _, err := reader.Read(value); err != nil {
            return err
        }
        tree.Insert(string(value)) // Вставляем значение в дерево
    }
    return nil
}

// SerializeText serializes the tree into a text file.
func SerializeText(tree *tree.FullTree, filename string) error {
    file, err := os.Create(filename)
    if err != nil {
        return err
    }
    defer file.Close()

    writer := bufio.NewWriter(file)
    data := tree.Get() // Получаем все элементы дерева в порядке обхода
    for _, value := range data {
        if _, err := writer.WriteString(value + "\n"); err != nil {
            return err
        }
    }
    return writer.Flush()
}

// DeserializeText deserializes the text file into the tree.
func DeserializeText(tree *tree.FullTree, filename string) error {
    file, err := os.Open(filename)
    if err != nil {
        return err
    }
    defer file.Close()

    scanner := bufio.NewScanner(file)
    tree.Clear() // Очищаем дерево перед десериализацией
    for scanner.Scan() {
        line := scanner.Text()
        if line == "" {
            continue // Пропускаем пустые строки
        }
        tree.Insert(line) // Вставляем значение в дерево
    }
    return scanner.Err()
}