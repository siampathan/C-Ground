#include <iostream>
#include <vector>

typedef std::vector<unsigned int> Sequence;

bool check(const Sequence& sequence)
{

  unsigned int fullSum = 0;
  for (auto x : sequence)
    fullSum += x;


  std::vector<bool> sums(fullSum + 1, false);

  std::vector<unsigned int> maxSum(sequence.size() + 1, 0);
  std::vector<unsigned int> minSum(sequence.size() + 1, fullSum + 1);
  minSum[0] = maxSum[0] = 0; 
  unsigned int fullMask = (1 << sequence.size()) - 1;


  for (unsigned int mask = 1; mask <= fullMask; mask++)
  {
    unsigned int sum  = 0;
    unsigned int size = 0;
    for (unsigned int element = 0; element < sequence.size(); element++)
    {
      unsigned int bit = 1 << element;
      if ((mask & bit) == 0)
        continue;

      sum += sequence[element];
      size++;
    }

    if (sums[sum])
      return false;
    sums[sum] = true;

    if (minSum[size] > sum)
      minSum[size] = sum;
    if (maxSum[size] < sum)
      maxSum[size] = sum;
  }

  for (size_t i = 1; i < sequence.size(); i++)
    if (maxSum[i] > minSum[i + 1])
      return false;

  return true;
}

#ifdef ORIGINAL

Sequence readLine()
{
  Sequence result;
  while (true)
  {
    result.push_back(0);

    char oneByte = 0;
    while (true)
    {
      oneByte = std::cin.get();

      if (!std::cin)
        return result;

      if (oneByte < '0' || oneByte > '9')
        break;

      result.back() *= 10;
      result.back() += oneByte - '0';
    }

    if (oneByte != ',')
      break;
  }
  return result;
}

#else

Sequence readLine()
{
  unsigned int size;
  std::cin >> size;

  Sequence result(size);
  for (auto& x : result)
    std::cin >> x;

  return result;
}

#endif

int main()
{
  unsigned int tests = 100;
#ifdef ORIGINAL
  unsigned int sum = 0;
#else
  std::cin >> tests;
#endif

  while (tests--)
  {
    auto sequence = readLine();

#ifdef ORIGINAL
    if (check(sequence))
      for (auto x : sequence)
        sum += x;
#else
    if (sequence.size() < 30)
      std::cout << (check(sequence) ? "YES" : "NO") << std::endl;
    else
      std::cout << "NO" << std::endl; 
#endif
  }

#ifdef ORIGINAL
  std::cout << sum << std::endl;
#endif

}