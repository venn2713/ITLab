#include <random>
#include "Fermat.h"
#include "Utility.h"

// Реализация функции для проверки простоты числа методом Ферма
bool isPrime_Fermat(int n, int iter)
{
  // Если число меньше или равно 1, оно не простое
  if (n <= 1) 
    return false;
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(2, n - 2);
  // Проведение теста Ферма iter раз
  for (int i = 0; i < iter; i++)
  {
    int a = dis(gen);
    if (modPow(a, n - 1, n) != 1) // Если условие Ферма не выполнено, число составное
      return false;
  }
  // Если все тесты Ферма пройдены, считаем число вероятно простым
  return true;
}
