#include <gtest/gtest.h>
#include "../structures/timer.h"
#include "../structures/tree.h"

// Тест вставки элементов и поиска
TEST(FullTreeTest, InsertAndFind) {
  Timer timer;
  timer.start();
  FullTree<string> tree;
  tree.insert("10");
  tree.insert("20");
  tree.insert("5");
  EXPECT_TRUE(tree.checkFull()); // Проверяем, что дерево остается полным после вставки
  timer.elapsed();
}

// Тест проверки полноты дерева
TEST(FullTreeTest, CheckFullTree) {
  Timer timer;
  timer.start();
  FullTree<string> tree;
  tree.insert("10");
  tree.insert("20");
  tree.insert("5");
  EXPECT_TRUE(tree.checkFull()); // Дерево должно быть полным
  timer.elapsed();
}

// Тест балансировки после вставки нескольких элементов
TEST(FullTreeTest, BalanceAfterInsertions) {
  Timer timer;
  timer.start();
  FullTree<string> tree;
  tree.insert("10");
  tree.insert("20");
  tree.insert("30");
  tree.insert("5");
  tree.insert("2");

  EXPECT_TRUE(tree.checkFull()); // Дерево должно оставаться полным
  timer.elapsed();
}