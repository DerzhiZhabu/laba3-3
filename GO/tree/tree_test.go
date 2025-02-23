package tree_test

import (
    "my_project/tree"
    "strconv"
    "testing"
)

func TestNewFullTree(t *testing.T) {
    tt := &tree.FullTree{}
    if !tt.IsEmpty() { // Используем метод IsEmpty вместо прямого доступа к root
        t.Errorf("Expected tree to be empty, but it is not")
    }
}

func TestInsert(t *testing.T) {
    tt := &tree.FullTree{}
    tt.Insert("apple")
    tt.Insert("banana")

    data := tt.Get()
    if len(data) != 2 || data[0] != "apple" || data[1] != "banana" {
        t.Errorf("Unexpected data in tree: %v", data)
    }
}

func TestCheckFull(t *testing.T) {
    t.Run("Full Tree", func(t *testing.T) {
        tt := &tree.FullTree{}
        tt.Insert("apple")
        tt.Insert("banana")
        tt.Insert("cherry")

        if !tt.CheckFull() {
            t.Errorf("Expected tree to be full, but it is not")
        }
    })
    t.Run("Not Full Tree", func(t *testing.T) {
        tt := &tree.FullTree{}
        tt.Insert("apple")
        tt.Insert("banana")

        if tt.CheckFull() {
            t.Errorf("Expected tree to be full, but it is not")
        }
    })
}

func TestMaxLength(t *testing.T) {
    tt := &tree.FullTree{}
    tt.Insert("short")
    tt.Insert("longer_string")
    tt.Insert("medium_length")

    maxLength := tt.MaxLength()
    if maxLength != 13 {
        t.Errorf("Expected max length to be 13, but got %d", maxLength)
    }
}

func TestGetHeight(t *testing.T) {
    t.Run("Empty Tree", func(t *testing.T) {
        tt := &tree.FullTree{}
        height := tt.GetHeight()
        if height != 0 {
            t.Errorf("Expected height to be 0, but got %d", height)
        }
    })

    t.Run("Non-Empty Tree", func(t *testing.T) {
        tt := &tree.FullTree{}
        tt.Insert("root")
        tt.Insert("left")
        tt.Insert("right")
        tt.Insert("left-left")

        height := tt.GetHeight()
        if height != 2 {
            t.Errorf("Expected height to be 2, but got %d", height)
        }
    })
}

func TestGet(t *testing.T) {
    tt := &tree.FullTree{}
    tt.Insert("apple")
    tt.Insert("banana")
    tt.Insert("cherry")

    data := tt.Get()
    expected := []string{"apple", "banana", "cherry"}
    if len(data) != len(expected) {
        t.Errorf("Expected %d elements, but got %d", len(expected), len(data))
        return
    }
    for i, v := range expected {
        if data[i] != v {
            t.Errorf("Expected %s at index %d, but got %s", v, i, data[i])
        }
    }
}

func TestClear(t *testing.T) {
    tt := &tree.FullTree{}
    tt.Insert("apple")
    tt.Insert("banana")

    tt.Clear()
    if !tt.IsEmpty() { // Используем метод IsEmpty вместо прямого доступа к root
        t.Errorf("Expected tree to be empty after clearing, but it is not")
    }
}

func TestPrint(t *testing.T) {

    tt := &tree.FullTree{}
    tt.Insert("root")
    tt.Insert("left")
    tt.Insert("right")

    tt.Print()
}

func TestLargeData(t *testing.T) {
    tt := &tree.FullTree{}
    for i := 0; i < 1000; i++ {
        tt.Insert("key" + strconv.Itoa(i))
    }

    data := tt.Get()
    if len(data) != 1000 {
        t.Errorf("Expected 1000 elements, but got %d", len(data))
    }
}