#include <cassert>
#include <iostream>
#include "BruteForce.h"
#include "Fermat.h"
#include "RabinMiller.h"

void runTests() 
{
  // Тест для алгоритма перебора
  assert(isPrime_BruteForce(2) == true);
  assert(isPrime_BruteForce(4) == false);

  // Тест для алгоритма Ферма
  assert(isPrime_Fermat(2, 5) == true);
  assert(isPrime_Fermat(4, 5) == false);

  // Тест для алгоритма Рабина-Миллера
  assert(isPrime_RabinMiller(2, 5) == true);
  assert(isPrime_RabinMiller(4, 5) == false);

  std::cout << "All tests passed!" << std::endl;
}
