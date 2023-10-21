#include <iostream>
#include <chrono>
#include "BruteForce.h"
#include "Fermat.h"
#include "RabinMiller.h"

// Функция для проведения экспериментов
void runExperiments() 
{
  // Примеры простых и составных чисел для тестирования
  int prime_numbers[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29 };
  int composite_numbers[] = { 4, 6, 8, 9, 10, 12, 14, 15, 16, 18 };
  int carmichael_numbers[] = { 41041, 62745, 63973, 75361, 101101, 126217 };

  // Измерение времени выполнения для алгоритма перебора
  auto start = std::chrono::high_resolution_clock::now();
  for (int num : prime_numbers)
    isPrime_BruteForce(num);
  auto stop = std::chrono::high_resolution_clock::now();

  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
  std::cout << "BruteForce Time: " << duration.count() << " microseconds" << std::endl;
}

int main() 
{
  // Запуск экспериментов
  runExperiments();
  return 0;
}
