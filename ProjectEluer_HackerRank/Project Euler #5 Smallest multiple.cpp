#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long gcd(long long a, long long b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

long long lcm(long long a, long long b) {
    return (a * b) / gcd(a, b);
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<long long> numbers(n);
        for (int i = 0; i < n; i++) {
            numbers[i] = i + 1;
        }

        long long result = numbers[0];
        for (int i = 1; i < n; i++) {
            result = lcm(result, numbers[i]);
        }

        cout << result << endl;
    }

    return 0;
}