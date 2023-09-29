#include <iostream>
#include <vector>
using namespace std;

int main(){

  unsigned int limit = 1000000;
 vector<unsigned int> phi(limit + 1);
  for (size_t i = 0; i < phi.size(); i++)
    phi[i] = i;

  for (unsigned int i = 2; i <= limit; i++){
 
    if (phi[i] == i)
      for (unsigned int k = 1; k * i <= limit; k++)
        phi[k * i] -= phi[k * i] / i;
  }

  vector<unsigned long long> sums(phi.size(), 0);
  for (unsigned int i = 2; i <= limit; i++)
    sums[i] = sums[i - 1] + phi[i];

  unsigned int tests = 1;
  cin >> tests;
  while (tests--) {
    cin >> limit;
   cout << sums[limit] << endl;
  }
}