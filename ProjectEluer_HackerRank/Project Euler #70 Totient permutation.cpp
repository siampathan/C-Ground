#include <iostream>
#include <vector>
using namespace std;

vector<unsigned int> primes;


unsigned int phi(unsigned int x, double minQuotient){
  
  auto result  = x;
  auto reduced = x;
  for (auto p : primes) {
    if (p*p > reduced)
      break;

    if (reduced % p != 0)
      continue;

    do {
      reduced /= p;
    } while (reduced % p == 0);

    result -= result / p;

    if (result * minQuotient < x)
      return result; 
  }
  if (result == x)
    return x - 1;

  if (reduced > 1)
    return result - result / reduced;
  else
    return result;
}

unsigned long long fingerprint(unsigned int x){
  unsigned long long result = 0;
  while (x > 0){
    auto digit = x % 10;
    x /= 10;

    unsigned long long shift = 1;
    for (unsigned int i = 0; i < digit; i++)
      shift *= 10;

    result += shift;
  }
  return result;
}

int main(){
  unsigned int last;
  cin >> last;
  
  primes.push_back(2);
  for (unsigned int i = 3; i*i < last; i += 2){
    bool isPrime = true;

    for (auto p : primes) {
      if (p*p > i)
        break;

      if (i % p == 0){
        isPrime = false;
        break;
      }
    }

    if (isPrime)
      primes.push_back(i);
  }

  unsigned int bestNumber  = 2;
  double       minQuotient = 999999;
  for (unsigned int n = 3; n < last; n++){
    auto phi_n = phi(n, minQuotient);
    double quotient = n / double(phi_n);
    if (minQuotient <= quotient)
      continue;
    if (fingerprint(phi_n) == fingerprint(n)){
      minQuotient = quotient;
      bestNumber  = n;
    }
  }

 cout << bestNumber << endl;
}