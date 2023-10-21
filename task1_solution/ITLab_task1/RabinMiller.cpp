#include <random>
#include "RabinMiller.h"
#include "Utility.h"

// ���������� ������� ��� �������� �������� ����� ������� ������-�������
bool isPrime_RabinMiller(int n, int iter)
{
  // ���� ����� ������ ��� ����� 1, ��� �� �������
  if (n <= 1)
    return false;
  int d = n - 1;
  int s = 0;
  // ������������� (n-1) ��� d*2^s
  while (d % 2 == 0)
  {
    d /= 2;
    ++s;
  }

  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(2, n - 2);

  // ���������� ����� ������-������� iter ���
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
    if (x != n - 1) // ���� ������� ������-������� �� ���������, ����� ���������
      return false;
  }
  // ���� ��� ����� ������-������� ��������, ������� ����� �������� �������
  return true;
}
