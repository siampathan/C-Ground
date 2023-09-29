#include <iostream>
#include <vector>


struct BillionNum : public std::vector<unsigned int>
{

  static const unsigned int MaxDigit = 1000000000;

  BillionNum(unsigned int x)
  {
    push_back(x);
  }


  void operator+=(const BillionNum& other)
  {
    
    if (size() < other.size())
      resize(other.size(), 0);

    unsigned int carry = 0;
    for (size_t i = 0; i < size(); i++)
    {
      
      carry += operator[](i);
      if (i < other.size())
        carry += other[i];
      else
        if (carry == 0)
          return;

      if (carry < MaxDigit)
      {

        operator[](i) = carry;
        carry         = 0;
      }
      else
      {
      
        operator[](i) = carry - MaxDigit;
        carry         = 1;
      }
    }

    if (carry > 0)
      push_back(carry);
  }
};

bool isPandigital(unsigned int x, unsigned int digits = 9)
{
  unsigned int mask = 0; 
  for (unsigned int i = 0; i < digits; i++)
  {
    auto current = x % 10;
    if (current == 0 || current > digits)
      return false;

    auto bit = 1 << current;
    if ((mask & bit) != 0)
      return false;

    mask |= bit;
    x    /= 10;
  }

  return true;
}

int main()
{
  unsigned int first  = 1;
  unsigned int second = 1; 
  unsigned int digits = 9; 

#ifndef ORIGINAL
  std::cin >> first >> second >> digits;
#endif

  if (first == 1 && digits == 1)
  {
    std::cout << "1" << std::endl;
    return 0;
  }

  unsigned long long Modulo = 1; 
  for (unsigned i = 1; i <= digits; i++)
    Modulo *= 10;

  BillionNum a = first;
  BillionNum b = second;

  for (unsigned int i = 2; i <= 2000000; i++)
  {
    auto lowest = b.front() % Modulo;
    bool isPanLow = isPandigital(lowest, digits);

    if (isPanLow)
    {
      unsigned long long highest = b.back();
      if (highest < Modulo && b.size() > 1)
        highest = highest * BillionNum::MaxDigit + b[b.size() - 2];

     
      while (highest >= Modulo)
        highest /= 10;

      if (isPandigital(highest, digits))
      {
        std::cout << i << std::endl;
        return 0;
      }
    }

    a += b;
    std::swap(a, b);

   
    if (a.size() > 10)
    {
      a.erase(a.begin() + 2);
      b.erase(b.begin() + 2);
    }
  }

  std::cout << "no solution" << std::endl;
}