package tree

import (
    "container/list"
    "fmt"
    "math"
)

// Узел дерева, хранящий строку
type NodeT struct {
    data  string
    left  *NodeT
    right *NodeT
}

// Полное дерево, работающее только со строками
type FullTree struct {
    root *NodeT
}

// Вставка нового значения в дерево
func (ft *FullTree) Insert(value string) {
    if ft.root == nil {
        ft.root = &NodeT{data: value}
        return
    }
    ft.insertHelper(ft.root, value)
}

func (ft *FullTree) IsEmpty() bool {
    return ft.root == nil
}

// Вспомогательная функция для вставки
func (ft *FullTree) insertHelper(node *NodeT, value string) {
    queue := list.New()
    queue.PushBack(node)
    for queue.Len() > 0 {
        element := queue.Remove(queue.Front()).(*NodeT)
        if element.left == nil {
            element.left = &NodeT{data: value}
            break
        } else {
            queue.PushBack(element.left)
        }
        if element.right == nil {
            element.right = &NodeT{data: value}
            break
        } else {
            queue.PushBack(element.right)
        }
    }
}

// Проверка, является ли дерево полным
func (ft *FullTree) CheckFull() bool {
    return ft.checkNode(ft.root)
}

// Рекурсивная проверка узла
func (ft *FullTree) checkNode(node *NodeT) bool {
    if node == nil {
        return true
    }
    if node.left == nil && node.right == nil {
        return true
    }
    if node.left == nil || node.right == nil {
        return false
    }
    return ft.checkNode(node.left) && ft.checkNode(node.right)
}

// Получение максимальной длины строки в дереве
func (ft *FullTree) MaxLength() int {
    if ft.root == nil {
        return 0
    }
    queue := list.New()
    queue.PushBack(ft.root)
    maxLen := 0
    for queue.Len() > 0 {
        element := queue.Remove(queue.Front()).(*NodeT)
        currentLen := len(element.data)
        if currentLen > maxLen {
            maxLen = currentLen
        }
        if element.left != nil {
            queue.PushBack(element.left)
        }
        if element.right != nil {
            queue.PushBack(element.right)
        }
    }
    return maxLen
}

// Получение высоты дерева
func (ft *FullTree) GetHeight() int {
    return ft.getHeight(ft.root)
}

// Рекурсивное получение высоты
func (ft *FullTree) getHeight(node *NodeT) int {
    if node == nil {
        return 0
    }
    height := 0
    for node.left != nil {
        node = node.left
        height++
    }
    return height
}

// Получение всех элементов дерева в порядке обхода
func (ft *FullTree) Get() []string {
    if ft.root == nil {
        return nil
    }
    queue := list.New()
    queue.PushBack(ft.root)
    var result []string
    for queue.Len() > 0 {
        element := queue.Remove(queue.Front()).(*NodeT)
        result = append(result, element.data)
        if element.left != nil {
            queue.PushBack(element.left)
        }
        if element.right != nil {
            queue.PushBack(element.right)
        }
    }
    return result
}

// Очистка дерева
func (ft *FullTree) Clear() {
    if ft.root == nil {
        return
    }
    queue := list.New()
    queue.PushBack(ft.root)
    for queue.Len() > 0 {
        element := queue.Remove(queue.Front()).(*NodeT)
        if element.left != nil {
            queue.PushBack(element.left)
        }
        if element.right != nil {
            queue.PushBack(element.right)
        }
        element.left = nil
        element.right = nil
    }
    ft.root = nil
}

// Печать дерева
func (ft *FullTree) Print() {
    ft.printTreeHelper()
}

// Вспомогательная функция для печати дерева
func (ft *FullTree) printTreeHelper() {
    if ft.root == nil {
        fmt.Println("Empty Tree")
        return
    }
    maxLen := ft.MaxLength()
    height := ft.GetHeight()
    queue := list.New()
    queue.PushBack(ft.root)
    level := 0
    for queue.Len() > 0 {
        size := queue.Len()
        padding := int(math.Max(float64(height-level)*float64(maxLen)+3*float64(height-level), 1))
        for i := 0; i < size; i++ {
            element := queue.Remove(queue.Front()).(*NodeT)
            if element != nil {
                fmt.Printf("%*s", padding, "")
                fmt.Printf("%s%*s", element.data, padding, "")
                queue.PushBack(element.left)
                queue.PushBack(element.right)
            } else {
                fmt.Printf("%*s", padding, "")
                fmt.Print(" ")
                fmt.Printf("%*s", padding, "")
            }
        }
        fmt.Println()
        level++
    }
}