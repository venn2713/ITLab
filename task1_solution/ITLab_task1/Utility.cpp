#include "Utility.h"

// Реализация вспомогательной функции для возведения числа в степень по модулю
long long modPow(long long base, long long exp, long long mod)
{
  long long result = 1;
  // Возведение числа в степень по модулю
  while (exp > 0)
  {
    if (exp % 2 == 1)
      result = (result * base) % mod;
    exp = exp >> 1;
    base = (base * base) % mod;
  }
  return result;
}
