#include <random>
#include "Fermat.h"
#include "Utility.h"

// ���������� ������� ��� �������� �������� ����� ������� �����
bool isPrime_Fermat(int n, int iter)
{
  // ���� ����� ������ ��� ����� 1, ��� �� �������
  if (n <= 1) 
    return false;
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(2, n - 2);
  // ���������� ����� ����� iter ���
  for (int i = 0; i < iter; i++)
  {
    int a = dis(gen);
    if (modPow(a, n - 1, n) != 1) // ���� ������� ����� �� ���������, ����� ���������
      return false;
  }
  // ���� ��� ����� ����� ��������, ������� ����� �������� �������
  return true;
}
