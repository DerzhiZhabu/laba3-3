#include <gtest/gtest.h>
#include "../structures/queue.h"
#include "../structures/timer.h"

// Тест добавления элементов и проверки первого элемента
TEST(QueueTest, PushAndFront) {
  Timer timer;
  timer.start();
  Queue<string> q;
  EXPECT_TRUE(q.isEmpty()); // Проверяем, что очередь пуста
  q.push("First");
  EXPECT_FALSE(q.isEmpty()); // Проверяем, что очередь больше не пуста
  EXPECT_EQ(q.front(), "First"); // Проверяем первый элемент
  q.push("Second");
  EXPECT_EQ(q.front(), "First"); // Первый элемент должен остаться "First"
  timer.elapsed();
}

// Тест удаления элементов
TEST(QueueTest, Pop) {
  Timer timer;
  timer.start();
  Queue<string> q;
  q.push("First");
  q.push("Second");
  EXPECT_EQ(q.front(), "First"); // Первый элемент должен быть "First"
  q.pop(); // Удаляем первый элемент
  EXPECT_EQ(q.front(), "Second"); // Теперь первый элемент должен быть "Second"
  q.pop(); // Удаляем второй элемент
  EXPECT_TRUE(q.isEmpty()); // Очередь должна стать пустой
  timer.elapsed();
}

// Тест попытки удаления из пустой очереди
TEST(QueueTest, PopFromEmptyQueue) {
  Timer timer;
  timer.start();
  Queue<string> q;
  EXPECT_THROW(q.pop(), runtime_error); // Ожидаем исключение при попытке удаления из пустой очереди
  timer.elapsed();
}

// Тест нескольких операций push и pop
TEST(QueueTest, MultiplePushAndPop) {
  Timer timer;
  timer.start();
  Queue<string> q;
  q.push("First");
  q.push("Second");
  q.push("Third");
  EXPECT_EQ(q.front(), "First"); // Первый элемент должен быть "First"
  q.pop(); // Удаляем первый элемент
  EXPECT_EQ(q.front(), "Second"); // Теперь первый элемент должен быть "Second"
  q.pop(); // Удаляем второй элемент
  EXPECT_EQ(q.front(), "Third"); // Теперь первый элемент должен быть "Third"
  q.pop(); // Удаляем третий элемент
  EXPECT_TRUE(q.isEmpty()); // Очередь должна стать пустой
  timer.elapsed();
}

// Тест очереди с одним элементом
TEST(QueueTest, QueueWithOneElement) {
  Timer timer;
  timer.start();
  Queue<string> q;
  q.push("OnlyElement");
  EXPECT_EQ(q.front(), "OnlyElement"); // Единственный элемент должен быть "OnlyElement"
  q.pop(); // Удаляем единственный элемент
  EXPECT_TRUE(q.isEmpty()); // Очередь должна стать пустой
  timer.elapsed();
}

// Тест длины очереди
TEST(QueueTest, QueueLength) {
  Timer timer;
  timer.start();
  Queue<string> q;
  EXPECT_EQ(q.len(), 0); // Длина пустой очереди должна быть 0
  q.push("First");
  EXPECT_EQ(q.len(), 1); // Длина очереди должна быть 1
  q.push("Second");
  EXPECT_EQ(q.len(), 2); // Длина очереди должна быть 2
  q.pop();
  EXPECT_EQ(q.len(), 1); // После удаления длина должна быть 1
  q.pop();
  EXPECT_EQ(q.len(), 0); // После полной очистки длина должна быть 0
  timer.elapsed();
}