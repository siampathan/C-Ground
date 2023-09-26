#include <set>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {

  set<unsigned int> smallPrimes;
  smallPrimes.insert(2);
  for (unsigned int i = 3; i*i <= 987654321; i += 2) {
    bool isPrime = true;
    for (auto p : smallPrimes) {
      if (p*p > i)
        break;

      if (i % p == 0) {
        isPrime = false;
        break;
      }
    }
    
    if (isPrime)
      smallPrimes.insert(i);
  }

 
  set<unsigned int> panPrimes;
  for (unsigned int digits = 2; digits <= 9; digits++) {
    string strNumber = "123456789";
    strNumber.erase(digits);

    do {
      unsigned int number = stoi(strNumber);

      bool isPrime = true;
      for (auto p : smallPrimes) {
        if (p*p > number)
          break;

        if (number % p == 0) {
          isPrime = false;
          break;
        }
      }

      if (isPrime)
        panPrimes.insert(number);
    } while (std::next_permutation(strNumber.begin(), strNumber.end()));
  }

  unsigned int tests;
  cin >> tests;
  while (tests--) {
    unsigned int limit;
    cin >> limit;

    auto i = panPrimes.upper_bound(limit);

    if (i == panPrimes.begin()) {
    cout << "-1" << endl;
      continue;
    }

    i--;
    cout << *i << endl;
  }
}