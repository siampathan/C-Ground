#include <iostream>
#include <vector>
#include <string>

typedef unsigned __int128 BigNum;

unsigned int solve(unsigned int x, unsigned int minAdd = 1)
{
  if (x == 0)
    return 1;

  unsigned long long result = 0;
  auto current = minAdd;
  while (current <= x)
  {

    result += solve(x - current, current*2);
    if (x >= 2*current)
      result += solve(x - 2*current, current*2);

    current *= 2;
  }

  return result;
}

std::vector<unsigned int> countZeros(BigNum x)
{
  std::vector<unsigned int> result;
  while ((x & 1) == 1)
    x >>= 1;

  auto consecutive = 0;
  while (x > 0)
  {
    if ((x & 1) == 0)
    {
      consecutive++;
    }
    else
    {
      result.insert(result.begin(), consecutive);
      consecutive = 0;
    }
    x >>= 1;
  }

  return result;
}

int main()
{
  
  std::string large;
  std::cin >> large;
  BigNum x = 0;

  for (auto c : large)
    x = x*10 + (c - '0');
  auto zeros = countZeros(x);

  unsigned long long result = 1;
  unsigned long long sum    = 1;
  for (unsigned int i = 0; i < zeros.size(); i++)
  {
    result += zeros[i] * sum;
    sum    += result;
  }
  std::cout << result << std::endl;
}