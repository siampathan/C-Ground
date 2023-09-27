#include <iostream>
#include <cmath>
using namespace std;

bool isPentagonal(unsigned long long x){

  unsigned long long n = (1 + sqrt(24*x + 1)) / 6;

  auto p_n = n * (3 * n - 1) / 2;
  return p_n == x;
}

int main(){
#ifdef ORIGINAL

  const unsigned int HugeNumber = 999999999;
  unsigned int best = HugeNumber;
  unsigned int n    = 2; 
  unsigned int last = 1;

  while (best == HugeNumber){

    auto p_n  = n * (3 * n - 1) / 2;
    if (p_n - last > best)
      break;

    for (unsigned int distance = 1; distance < n; distance++)  {
  
      auto x   = n - distance;
      auto p_x = x * (3 * x - 1) / 2;

    
      auto sum        = p_n + p_x;
      auto difference = p_n - p_x;

      if (difference > best)
        break;

      if (isPentagonal(sum) && isPentagonal(difference))
        best = difference;
    }
    
    last = p_n;
    n++;
  }
  cout << best << endl;

#else

  unsigned int maxIndex;
  unsigned int distance;
  cin >> maxIndex >> distance;

  for (unsigned long long n = distance + 1; n <= maxIndex; n++) {
    auto p_n = n * (3 * n - 1) / 2;

    auto x   = n - distance;
    auto p_x = x * (3 * x - 1) / 2;

    auto sum        = p_n + p_x;
    auto difference = p_n - p_x;

    if (isPentagonal(sum) || isPentagonal(difference))
     cout << p_n <<endl;
  }
#endif
}