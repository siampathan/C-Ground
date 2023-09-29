#include <vector>
#include <iostream>
#include <algorithm>

bool isPalindrome(unsigned int x)
{
  auto reduced = x / 10;
  auto reverse = x % 10;
  
  if (reverse == 0)
    return false;

  while (reduced > 0)
  {
    
    reverse *= 10;
    reverse += reduced % 10;
    reduced /= 10;
  }

  return reverse == x;
}


int main()
{
  unsigned int tests = 1;
  std::cin >> tests;
  while (tests--)
  {
    unsigned int limit  = 100000000;
    unsigned int stride = 1; 

    std::cin >> limit >> stride;

    std::vector<unsigned int> solutions;
    for (unsigned long long first = 1; 2*first*first < limit; first++)
    {
      auto next = first + stride;

      auto current = first * first + next * next;
      while (current < limit)
      {
        if (isPalindrome(current))
          solutions.push_back(current);

        next    += stride;
        current += next * next;
      }
    }

    std::sort(solutions.begin(), solutions.end());
    auto garbage = std::unique(solutions.begin(), solutions.end());
    solutions.erase(garbage, solutions.end());

    unsigned long long sum = 0;
    for (auto x : solutions)
      sum += x;

    std::cout << sum << std::endl;
  }

}