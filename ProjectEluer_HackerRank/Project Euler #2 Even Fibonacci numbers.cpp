#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long n;
        cin >> n;

        long long a = 1; // First term
        long long b = 2; // Second term
        long long sum = 0;

        while (b <= n) {
            if (b % 2 == 0) {
                sum += b;
            }
            long long next_term = a + b;
            a = b;
            b = next_term;
        }

        cout << sum << endl;
    }

}