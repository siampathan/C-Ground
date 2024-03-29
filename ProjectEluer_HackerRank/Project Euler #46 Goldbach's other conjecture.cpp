#include <set>
#include <iostream>
using namespace std;

int main() {
  const unsigned int MaxPrime = 500000;

  set<unsigned int> primes;
  primes.insert(2);
  for (unsigned int i = 3; i < MaxPrime; i += 2) {
    bool isPrime = true;
   
    for (auto p : primes) {
     
      if (p*p > i)
          break;

      if (i % p == 0) {
        isPrime = false;
        break;
      }
    }

    if (isPrime)
      primes.insert(i);
  }

#ifdef ORIGINAL
  for (unsigned int i = 9; i <= MaxPrime; i += 2)  {
    if (primes.count(i) != 0)
      continue;

    bool refuteConjecture = true;

    for (unsigned int j = 1; 2*j*j < i; j++)  {
      auto check = i - 2*j*j;
      if (primes.count(check) != 0) {
        refuteConjecture = false;
        break;
      }
    }

    if (refuteConjecture) {
      cout << i << endl;
      break;
    }
  }

#else

  unsigned int tests;
  cin >> tests;
  while (tests--){
    unsigned int i;
    cin >> i;

    unsigned int solutions = 0;
    for (unsigned int j = 1; 2*j*j < i; j++) {
      unsigned int check = i - 2*j*j;
      if (primes.count(check) != 0)
        solutions++;
    }

   cout << solutions << endl;
  }
#endif
}