#include <iostream>
#include <vector>
#include <map>

typedef std::vector<unsigned int> Chain;

bool search(Chain& chain, unsigned int exponent, unsigned int maxDepth)
{
  if (chain.size() > maxDepth)
    return false;

  auto last = chain.back();
  for (size_t i = 0; i < chain.size(); i++)
  {
    auto sum = chain[chain.size() - 1 - i] + last; 
    if (sum == exponent)
      return true;

    chain.push_back(sum);
    if (search(chain, exponent, maxDepth))
      return true;

    chain.pop_back();
  }

  return false;
}

Chain findChain(unsigned int exponent)
{
  static std::map<unsigned int, Chain> cache;
  auto lookup = cache.find(exponent);
  if (lookup != cache.end())
    return lookup->second;

  Chain chain;
  unsigned int depth = 1;
  while (true)
  {
    chain = { 1 };
    if (search(chain, exponent, depth))
      break;

    depth++;
  }

  cache[exponent] = chain;
  return chain;
}

void print(const Chain& chain)
{

  std::cout << (chain.size() - 1) << std::endl;
  for (size_t i = 1; i < chain.size(); i++)
  {
    auto sum  = chain[i];
    auto add1 = chain[i - 1];
    auto add2 = sum - add1;

    std::cout << "n";
    if (add1 > 1)
      std::cout << "^" << add1;
    std::cout << " * n";
    if (add2 > 1)
      std::cout << "^" << add2;
    std::cout << " = n^" << sum << std::endl;
  }
}

int main()
{
#ifdef ORIGINAL

  unsigned int sum = 0;

  for (unsigned int exponent = 2; exponent <= 200; exponent++)
  {
    auto chain = findChain(exponent);
    sum += chain.size();
  }
  std::cout << sum << std::endl;

#else

  unsigned int tests;
  std::cin >> tests;
  while (tests--)
  {
    unsigned int exponent;
    std::cin >> exponent;

   
    auto chain = findChain(exponent);
   
    chain.push_back(exponent);
    print(chain);
  }

#endif

}