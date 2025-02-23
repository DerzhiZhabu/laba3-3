#include <gtest/gtest.h>
#include "../structures/hash.h"
#include "../structures/timer.h"

// Тест конструктора и деструктора
TEST(HashTableTest, ConstructorDestructor) {
  Timer timer;
  timer.start();
  HashTable<string> ht;
  SUCCEED();
  timer.elapsed();
}

// Тест конструктора и деструктора
TEST(HashTableTest, KeyExists) {
  Timer timer;
  timer.start();
  HashTable<string> ht;
  ht.Add("key1", "value1");
  EXPECT_THROW(ht.Add("key1", "value2"), runtime_error);
  SUCCEED();
  timer.elapsed();
}

TEST(HashTableTest, NoSuchKey) {
  Timer timer;
  timer.start();
  HashTable<string> ht;
  EXPECT_THROW(ht.Get("key1"), runtime_error);
  SUCCEED();
  timer.elapsed();
}

TEST(HashTableTest, NoSuchKeyRemove) {
  Timer timer;
  timer.start();
  HashTable<string> ht;
  EXPECT_THROW(ht.Remove("key1"), runtime_error);
  SUCCEED();
  timer.elapsed();
}

// Тест вставки и получения значений
TEST(HashTableTest, InsertAndRetrieve) {
  Timer timer;
  timer.start();
  HashTable<string> ht;
  ht.Add("key1", "value1");
  ht.Add("key2", "value2");
  EXPECT_EQ(ht.Get("key1"), "value1");
  EXPECT_EQ(ht.Get("key2"), "value2");

  // Проверяем, что несуществующий ключ выбрасывает исключение
  EXPECT_THROW(ht.Get("key3"), runtime_error);
  timer.elapsed();
}

// Тест перезаписи значения
TEST(HashTableTest, OverwriteValue) {
  Timer timer;
  timer.start();
  HashTable<string> ht;
  ht.Add("key1", "value1");
  EXPECT_EQ(ht.Get("key1"), "value1");

  // Перезаписываем значение
  ht.Remove("key1");
  ht.Add("key1", "new_value");
  EXPECT_EQ(ht.Get("key1"), "new_value");
  timer.elapsed();
}

// Тест обработки коллизий
TEST(HashTableTest, HandleCollisions) {
  Timer timer;
  timer.start();
  HashTable<string> ht;
  std::string key1 = "000";
  std::string key2 = "369";

  // Добавляем ключи, которые могут вызвать коллизию
  ht.Add(key1, "value1");
  ht.Add(key2, "value2");

  EXPECT_NE(ht.Get(key1), ht.Get(key2));
  EXPECT_EQ(ht.Get(key1), "value1");
  EXPECT_EQ(ht.Get(key2), "value2");
  timer.elapsed();
}

// Тест деструктора на освобождение памяти
TEST(HashTableTest, DestructorHandlesMemory) {
  Timer timer;
  timer.start();
  HashTable<string>* ht = new HashTable<string>();
  ht->Add("key1", "value1");
  delete ht;
  SUCCEED();
  timer.elapsed();
}

// Тест работы с большим количеством данных
TEST(HashTableTest, LargeData) {
  Timer timer;
  timer.start();
  HashTable<string> ht;
  for (int i = 0; i < 1000; ++i) {
    ht.Add("key" + std::to_string(i), "value" + std::to_string(i));
  }
  for (int i = 0; i < 1000; ++i) {
    EXPECT_EQ(ht.Get("key" + std::to_string(i)), "value" + std::to_string(i));
  }
  timer.elapsed();
}

// Тест пустого значения
TEST(HashTableTest, EmptyValue) {
  Timer timer;
  timer.start();
  HashTable<string> ht;
  ht.Add("key1", "");
  EXPECT_EQ(ht.Get("key1"), "");
  timer.elapsed();
}

// Тест повторного использования ключа
TEST(HashTableTest, ReuseKey) {
  Timer timer;
  timer.start();
  HashTable<string> ht;
  ht.Add("key1", "value1");
  EXPECT_EQ(ht.Get("key1"), "value1");

  // Удаляем ключ и добавляем его снова
  ht.Remove("key1");
  ht.Add("key1", "value1_appended");
  EXPECT_EQ(ht.Get("key1"), "value1_appended");
  timer.elapsed();
}

// Тест удаления ключа
TEST(HashTableTest, RemoveKey) {
  Timer timer;
  timer.start();
  HashTable<string> ht;
  ht.Add("key1", "value1");
  EXPECT_EQ(ht.Get("key1"), "value1");

  // Удаляем ключ
  ht.Remove("key1");
  EXPECT_THROW(ht.Get("key1"), runtime_error);
  timer.elapsed();
}