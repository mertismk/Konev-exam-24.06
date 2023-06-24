#include "metric.h"
#include <cassert>
#include <iostream>

void test_add_metr() {
  MetricRegister &registry = MetricRegister::getInstance();

  // Добавляем метрики
  assert(registry.add_metr(1, 10, 5));
  assert(registry.add_metr(2, 20, 10));
  assert(registry.add_metr(3, 15, 8));
  assert(!registry.add_metr(
      2, 30, 15)); // Попытка добавить существующую метрику. Тест 1

  // Проверяем, что метрики были добавлены правильно
  assert(registry.count_cometr(1) == 15); // Тест 2
  assert(registry.count_cometr(2) == 30); // Тест 3
  assert(registry.count_cometr(3) == 23); // Тест 4
  assert(registry.count_cometr(4) == -1); // Метрика не найдена. Тест 5

  assert(!registry.add_metr(0, 10, 5)); // Некорректный ключ. Тест 6
  assert(!registry.add_metr(4, -10, 5)); // Некорректное время отклика. Тест 7
  assert(!registry.add_metr(5, 10, -5)); // Некорректное время ожидания. Тест 8

  assert(registry.add_metr(6, 5000, 5000));
  assert(registry.count_cometr(6) == 10000); // Тест 9

  assert(!registry.add_metr(
      -1, -10, -5)); // Некорректные значения ключа и времени. Тест 10
}

int main() {
  // Тесты
  std::cout << "Тесты:" << std::endl;
  test_add_metr();
  std::cout << "Все тесты пройдены!" << std::endl << std::endl;

  MetricRegister &registry = MetricRegister::getInstance();
  registry.show_metr();
  return 0;
}