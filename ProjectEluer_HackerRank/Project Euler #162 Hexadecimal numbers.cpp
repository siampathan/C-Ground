#include <iostream>
#include <iomanip>

unsigned long long count(unsigned int digits, bool haveAny = false,
  bool haveZero = false, bool haveOne = false, bool haveA = false)
{
  if (haveZero && haveOne && haveA && digits < 15)
    return 1ULL << (4 * digits);
  if (digits == 0)
    return 0;
  unsigned long long next = count(digits - 1, true, haveZero, haveOne, haveA);
  unsigned long long result = 13 * next;
  result += haveZero ? next : count(digits - 1, haveAny, haveAny, haveOne, haveA);
  result += haveOne  ? next : count(digits - 1, true, haveZero, true, haveA);

  result += haveA    ? next : count(digits - 1, true, haveZero, haveOne, true);

#ifndef ORIGINAL
  result %= 1000000007ULL;
#endif

  return result;
}

int main()
{
#ifdef ORIGINAL
  std::cout << std::uppercase << std::hex << count(16) << std::endl;
#else
  unsigned int digits;
  std::cin >> digits;
  std::cout << count(digits) << std::endl;
#endif

}