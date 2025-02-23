#include <gtest/gtest.h>
#include "../structures/stack.h"
#include "../structures/timer.h"

// Тест добавления и удаления элементов
TEST(StackTest, PushAndPop) {
  Timer timer;
  timer.start();
  Stack<string> s;
  EXPECT_TRUE(s.isEmpty()); // Проверяем, что стек пуст
  s.push("A");
  EXPECT_FALSE(s.isEmpty()); // После добавления стек должен быть не пустым
  EXPECT_EQ(s.len(), 1); // Длина стека должна быть 1
  EXPECT_EQ(s.pop(), "A"); // Удаляем элемент, проверяем его значение
  EXPECT_TRUE(s.isEmpty()); // Стек снова должен быть пустым
  timer.elapsed();
}

// Тест попытки удаления из пустого стека
TEST(StackTest, PopFromEmptyStack) {
  Timer timer;
  timer.start();
  Stack<string> s;
  EXPECT_THROW(s.pop(), runtime_error); // Ожидаем исключение при попытке удаления из пустого стека
  timer.elapsed();
}


// Тест нескольких операций push и pop
TEST(StackTest, MultiplePushAndPop) {
  Timer timer;
  timer.start();
  Stack<string> s;
  s.push("A");
  s.push("B");
  s.push("C");
  EXPECT_EQ(s.len(), 3); // Длина стека должна быть 3
  EXPECT_EQ(s.pop(), "C"); // Удаляем верхний элемент, он должен быть "C"
  EXPECT_EQ(s.pop(), "B"); // Удаляем верхний элемент, он должен быть "B"
  EXPECT_EQ(s.pop(), "A"); // Удаляем верхний элемент, он должен быть "A"
  EXPECT_TRUE(s.isEmpty()); // Стек должен стать пустым
  timer.elapsed();
}

// Тест длины стека
TEST(StackTest, StackLength) {
  Timer timer;
  timer.start();
  Stack<string> s;
  EXPECT_EQ(s.len(), 0); // Длина пустого стека должна быть 0
  s.push("A");
  EXPECT_EQ(s.len(), 1); // После добавления одного элемента длина должна быть 1
  s.push("B");
  EXPECT_EQ(s.len(), 2); // После добавления второго элемента длина должна быть 2
  s.pop();
  EXPECT_EQ(s.len(), 1); // После удаления одного элемента длина должна быть 1
  s.pop();
  EXPECT_EQ(s.len(), 0); // После полной очистки длина должна быть 0
  timer.elapsed();
}

// Тест очистки стека
TEST(StackTest, ClearStack) {
  Timer timer;
  timer.start();
  Stack<string> s;
  s.push("A");
  s.push("B");
  s.clear(); // Очищаем стек
  EXPECT_TRUE(s.isEmpty()); // Стек должен быть пустым
  EXPECT_THROW(s.pop(), runtime_error); // Попытка удаления элемента должна выбросить исключение
  timer.elapsed();
}

// Тест работы с большим количеством данных
TEST(StackTest, LargeData) {
  Timer timer;
  timer.start();
  Stack<string> s;
  for (int i = 0; i < 1000; ++i) {
    s.push("Item" + to_string(i)); // Добавляем 1000 элементов
  }
  EXPECT_EQ(s.len(), 1000); // Длина стека должна быть 1000
  for (int i = 999; i >= 0; --i) {
    EXPECT_EQ(s.pop(), "Item" + to_string(i)); // Проверяем верхний элемент
  }
  EXPECT_TRUE(s.isEmpty()); // Стек должен стать пустым
  timer.elapsed();
}