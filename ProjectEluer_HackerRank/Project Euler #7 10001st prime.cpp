#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 104729; // 10^4th prime number (based on constraints)

void sieve(vector<bool>& isPrime) {
    int n = isPrime.size();
    isPrime[0] = isPrime[1] = false;
    
    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }
}

int findNthPrime(int n) {
    vector<bool> isPrime(MAXN + 1, true);
    sieve(isPrime);
    
    int count = 0;
    for (int i = 2; i <= MAXN; i++) {
        if (isPrime[i]) {
            count++;
            if (count == n) {
                return i;
            }
        }
    }
    
    return -1; // To handle unexpected cases
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int result = findNthPrime(n);
        cout << result << endl;
    }

    return 0;
}