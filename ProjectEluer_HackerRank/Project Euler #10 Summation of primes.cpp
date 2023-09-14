#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 1000006;

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

long long sumOfPrimes(int n) {
    vector<bool> isPrime(MAXN, true);
    sieve(isPrime);

    long long sum = 0;
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            sum += i;
        }
    }

    return sum;
}