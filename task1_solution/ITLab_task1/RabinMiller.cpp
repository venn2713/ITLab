#include <random>
#include "RabinMiller.h"
#include "Utility.h"

// Реализация функции для проверки простоты числа методом Рабина-Миллера
bool isPrime_RabinMiller(int n, int iter)
{
  // Если число меньше или равно 1, оно не простое
  if (n <= 1)
    return false;
  int d = n - 1;
  int s = 0;
  // Представление (n-1) как d*2^s
  while (d % 2 == 0)
  {
    d /= 2;
    ++s;
  }

  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(2, n - 2);

  // Проведение теста Рабина-Миллера iter раз
  for (int i = 0; i < iter; i++)
  {
    int a = dis(gen);
    long long x = modPow(a, d, n);
    if (x == 1 || x == n - 1)
      continue;
    for (int r = 0; r < s; r++) 
    {
      x = modPow(x, 2, n);
      if (x == n - 1)
        break;
    }
    if (x != n - 1) // Если условие Рабина-Миллера не выполнено, число составное
      return false;
  }
  // Если все тесты Рабина-Миллера пройдены, считаем число вероятно простым
  return true;
}
