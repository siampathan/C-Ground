#include <iostream>
#include <vector>
#include <algorithm>


unsigned int digitRoot(unsigned int x)
{
  unsigned int result = 0;
  while (x > 0)
  {
    result += x % 10;
    x      /= 10;
  }

  if (result >= 10)
    result = digitRoot(result);

  return result;
}

int main()
{
  unsigned int limit = 1000000;

#ifndef ORIGINAL
  limit = 1;
  unsigned int tests = 1;
  std::cin >> tests;
  std::vector<unsigned int> input(tests);
  for (auto& x : input)
  {
    std::cin >> x;
    if (limit < x)
      limit = x;
  }
#endif

  std::vector<unsigned char> mdrs(limit + 1, 0);

  for (unsigned int i = 2; i <= limit; i++)
    mdrs[i] = digitRoot(i);

  for (unsigned int a = 2; a <= limit; a++)
    for (unsigned int b = 2; a * b <= limit && b <= a; b++)
      if (mdrs[a * b] < mdrs[a] + mdrs[b])
        mdrs[a * b] = mdrs[a] + mdrs[b];


#ifdef ORIGINAL
  unsigned int sum = 0;
  for (unsigned int i = 2; i < limit; i++)
    sum += mdrs[i];

  std::cout << sum << std::endl;
#else
  std::vector<unsigned int> sums(mdrs.size(), 0);
  for (unsigned int i = 2; i < sums.size(); i++)
    sums[i] = sums[i-1] + mdrs[i];
  for (auto x : input)
    std::cout << sums[x] << std::endl;
#endif

}