#include <vector>
#include <iostream>
using namespace std;

int main(){

  unsigned int maxN      = 100;

  unsigned long long maxNumber = 1000000;
  cin >> maxN >> maxNumber;

  
  unsigned int bigNumbers = 0;

 vector<vector<unsigned long long>> combinations(maxN + 1);

  for (unsigned int n = 0; n <= maxN; n++) {
    combinations[n].resize(n + 1, 0);
    combinations[n][0] = combinations[n][n] = 1;
  }

  
  for (unsigned int n = 1; n <= maxN; n++)
    for (unsigned int k = 1; k < n; k++) {
      auto sum = combinations[n - 1][k - 1] + combinations[n - 1][k];
    
      if (sum > maxNumber) {
        sum = maxNumber + 1;
    
        bigNumbers++;
      }

      combinations[n][k] = sum;
    }

  cout << bigNumbers << endl;
}