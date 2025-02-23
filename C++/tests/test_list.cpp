#include <gtest/gtest.h>
#include "../structures/list.h"
#include "../structures/timer.h"

// Тест добавления элемента в конец списка
TEST(ListTest, AddTail) {
  Timer timer;
  timer.start();
  List<string> list;
  list.push("First");
  list.push("Second");
  EXPECT_EQ(list.len(), 2);
  EXPECT_EQ(list[0], "First");
  EXPECT_EQ(list[1], "Second");
  timer.elapsed();
}

// Тест добавления элемента в начало списка
TEST(ListTest, AddHead) {
  Timer timer;
  timer.start();
  List<string> list;
  list.pushf("First");
  list.pushf("Second");
  EXPECT_EQ(list.len(), 2);
  EXPECT_EQ(list[0], "Second");
  EXPECT_EQ(list[1], "First");
  timer.elapsed();
}

// Тест удаления последнего элемента
TEST(ListTest, RemoveTail) {
  Timer timer;
  timer.start();
  List<string> list;
  list.push("First");
  list.push("Second");
  list.pop(); // Удаляем последний элемент
  EXPECT_EQ(list.len(), 1);
  EXPECT_EQ(list[0], "First");
  timer.elapsed();
}

// Тест удаления первого элемента
TEST(ListTest, RemoveHead) {
  Timer timer;
  timer.start();
  List<string> list;
  list.push("First");
  list.push("Second");
  list.del(0); // Удаляем первый элемент
  EXPECT_EQ(list.len(), 1);
  EXPECT_EQ(list[0], "Second");
  timer.elapsed();
}

// Тест удаления по значению
TEST(ListTest, RemoveByValue) {
  Timer timer;
  timer.start();
  List<string> list;
  list.push("First");
  list.push("Second");
  list.remove("First"); // Удаляем элемент по значению
  EXPECT_EQ(list.len(), 1);
  EXPECT_EQ(list[0], "Second");
  timer.elapsed();
}

// Тест поиска элемента
TEST(ListTest, Search) {
  Timer timer;
  timer.start();
  List<string> list;
  list.push("First");
  list.push("Second");
  EXPECT_EQ(list.find("First"), 0); // Проверяем индекс найденного элемента
  EXPECT_EQ(list.find("Second"), 1);
  EXPECT_EQ(list.find("NonExistent"), -1); // Проверяем отсутствие элемента
  timer.elapsed();
}

// Тест вставки элемента по индексу
TEST(ListTest, InsertAtIndex) {
  Timer timer;
  timer.start();
  List<string> list;
  list.push("First");
  list.push("Third");
  list.insert("Second", 1); // Вставляем элемент по индексу
  EXPECT_EQ(list.len(), 3);
  EXPECT_EQ(list[0], "First");
  EXPECT_EQ(list[1], "Second");
  EXPECT_EQ(list[2], "Third");
  timer.elapsed();
}


// Тест выхода за пределы списка
TEST(ListTest, OutOfBoundsAccess) {
  Timer timer;
  timer.start();
  List<string> list;
  list.push("First");
  EXPECT_THROW(list[1], runtime_error); // Проверяем исключение при доступе к несуществующему индексу
  timer.elapsed();
}

// Тест удаления несуществующего элемента
TEST(ListTest, RemoveNonExistentElement) {
  Timer timer;
  timer.start();
  List<string> list;
  list.push("First");
  EXPECT_THROW(list.remove("NonExistent"), runtime_error); // Проверяем исключение при удалении несуществующего элемента
  timer.elapsed();
}

// Тест работы с большим количеством данных
TEST(ListTest, LargeData) {
  Timer timer;
  timer.start();
  List<string> list;
  for (int i = 0; i < 1000; ++i) {
    list.push("Item" + to_string(i));
  }
  EXPECT_EQ(list.len(), 1000);
  for (int i = 0; i < 1000; ++i) {
    EXPECT_EQ(list[i], "Item" + to_string(i));
  }
  timer.elapsed();
}