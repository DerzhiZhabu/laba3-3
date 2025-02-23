#include <gtest/gtest.h>
#include "../structures/arr.h"
#include "../structures/timer.h"

// Тест конструктора и размера массива
TEST(ArrayTest, ConstructorAndSize) {
  Timer timer;
  timer.start();
  Array<string> arr;
  EXPECT_EQ(arr.len(), 8); // Проверяем начальную длину массива
  timer.elapsed();
}

// Тест метода push
TEST(ArrayTest, Push) {
  Timer timer;
  timer.start();
  Array<string> arr;
  arr.push("Hello");
  arr.push("World");
  EXPECT_EQ(arr.len(), 8); // Проверяем длину массива после добавления элементов
  EXPECT_EQ(arr[0], "Hello"); // Проверяем значение первого элемента
  EXPECT_EQ(arr[1], "World"); // Проверяем значение второго элемента
  timer.elapsed();
}

// Тест метода remove
TEST(ArrayTest, Remove) {
  Timer timer;
  timer.start();
  Array<string> arr;
  arr.push("One");
  arr.push("Two");
  arr.push("Three");
  arr.remove("Two"); // Удаляем элемент "Two"
  EXPECT_EQ(arr.len(), 8); // Проверяем длину массива после удаления
  EXPECT_EQ(arr[0], "One"); // Проверяем значение первого элемента
  EXPECT_EQ(arr[2], "Three"); // Проверяем значение второго элемента
  timer.elapsed();
}

// Тест автоматического увеличения размера массива
TEST(ArrayTest, PushResizesArray) {
  Timer timer;
  timer.start();
  Array<string> arr;
  for (int i = 0; i < 20; ++i) {
    arr.push("String" + to_string(i)); // Добавляем 20 элементов
  }
  EXPECT_EQ(arr.len(), 32); // Проверяем длину массива
  timer.elapsed();
}

// Тест оператора индексации
TEST(ArrayTest, IndexingOperator) {
  Timer timer;
  timer.start();
  Array<string> arr;
  arr.push("A");
  arr.push("B");
  EXPECT_EQ(arr[0], "A"); // Проверяем значение первого элемента
  EXPECT_EQ(arr[1], "B"); // Проверяем значение второго элемента
  timer.elapsed();
}

// Тест выхода за пределы массива
TEST(ArrayTest, IndexOutOfBounds) {
  Timer timer;
  timer.start();
  Array<string> arr;
  arr.push("A");
  EXPECT_THROW(arr[1], runtime_error); // Ожидаем исключение при доступе к несуществующему индексу
  timer.elapsed();
}

// Тест деструктора
TEST(ArrayTest, DestructorClearsArray) {
  Timer timer;
  timer.start();
  Array<string>* arr = new Array<string>();
  arr->push("A");
  delete arr; // Удаляем массив
  timer.elapsed();
}

// Тест метода find
TEST(ArrayTest, FindElement) {
  Timer timer;
  timer.start();
  Array<string> arr;
  arr.push("One");
  arr.push("Two");
  arr.push("Three");
  EXPECT_EQ(arr.find("Two"), 1); // Проверяем индекс найденного элемента
  EXPECT_EQ(arr.find("Four"), -1); // Проверяем отсутствие элемента
  timer.elapsed();
}

// Тест метода set
TEST(ArrayTest, SetElement) {
  Timer timer;
  timer.start();
  Array<string> arr;
  arr.push("A");
  arr.set("B", 0); // Изменяем значение первого элемента
  EXPECT_EQ(arr[0], "B"); // Проверяем новое значение первого элемента
  timer.elapsed();
}