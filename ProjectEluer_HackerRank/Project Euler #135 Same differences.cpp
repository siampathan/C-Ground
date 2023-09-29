#include <iostream>
#include <vector>


int main()
{
#ifdef ORIGINAL
  unsigned int limit = 1000000; 
#else
  unsigned int limit = 8000001; 
#endif


  std::vector<unsigned int> solutions(limit, 0);
  for (unsigned int a = 1; a < limit; a++)
    for (auto b = (a + 3) / 4; b < a; b++)
    {
      auto current = a * (4*b - a);
      if (current >= limit)
        break;

      solutions[current]++;
    }

#ifdef ORIGINAL
  unsigned int count = 0;
  for (auto s : solutions)
    if (s == 10)
      count++;
  std::cout << count << std::endl;

#else

  unsigned int tests;
  std::cin >> tests;
  while (tests--)
  {
    unsigned int pos;
    std::cin >> pos;
    std::cout << solutions[pos] << std::endl;
  }
#endif
}