#include <iostream>
#include <cmath>
using namespace std;

long long largestPrimeFactor(long long n) {
    long long largestFactor = -1;

    while (n % 2 == 0) {
        largestFactor = 2;
        n /= 2;
    }


    for (long long i = 3; i <= sqrt(n); i += 2) {
        while (n % i == 0) {
            largestFactor = i;
            n /= i;
        }
    }

    if (n > 2) {
        largestFactor = n;
    }

    return largestFactor;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long n;
        cin >> n;

        long long result = largestPrimeFactor(n);
        cout << result << endl;
    }

}