#include <string>
#include <iostream>
#include <algorithm>
using namespace std;


unsigned long long str2num(const string& x) {

  unsigned long long result = 0;
  for (auto c : x) {
      result *= 10;
      result += c - '0'; 
  }
  return result;
}

int main() {

  string pan = "0123456789";

  unsigned int maxDigit;
  cin >> maxDigit;
  pan.erase(maxDigit + 1);

  const unsigned int primes[] = { 2,3,5,7,11,13,17 };

  unsigned long long sum = 0;

  do {
    bool ok = true;

    for (unsigned int i = 0; i + 2 < maxDigit; i++) {
      string check = pan.substr(i + 1, 3);
      if (str2num(check) % primes[i] != 0) {
        ok = false;
        break;
      }
    }

    if (ok)
      sum += str2num(pan);
  } while (next_permutation(pan.begin(), pan.end()));

  cout << sum << endl;
  return 0;
}