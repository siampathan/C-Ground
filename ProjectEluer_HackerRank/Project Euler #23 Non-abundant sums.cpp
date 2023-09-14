#include <iostream>
#include <vector>
using namespace std;

vector<int> properDivisors(int n) {
    vector<int> divisors;
    for (int i = 1; i <= n / 2; ++i) {
        if (n % i == 0) {
            divisors.push_back(i);
        }
    }
    return divisors;
}

bool isAbundant(int n) {
    vector<int> divisors = properDivisors(n);
    int divisorSum = 0;
    for (int divisor : divisors) {
        divisorSum += divisor;
    }
    return divisorSum > n;
}

int main() {
    int T;
    cin >> T;

    const int limit = 28123;
    bool canBeExpressed[limit * 2 + 1] = {false}; 

    vector<int> abundantNumbers;
    for (int i = 12; i <= limit; ++i) {
        if (isAbundant(i)) {
            abundantNumbers.push_back(i);
            for (int j = 0; j < abundantNumbers.size(); ++j) {
                int sum = i + abundantNumbers[j];
                if (sum <= limit * 2) {
                    canBeExpressed[sum] = true;
                }
            }
        }
    }

    for (int t = 0; t < T; ++t) {
        int N;
        cin >> N;

        if (N > limit || canBeExpressed[N]) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}