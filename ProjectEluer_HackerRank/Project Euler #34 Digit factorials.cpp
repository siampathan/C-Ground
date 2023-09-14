#include <iostream>

using namespace std;

int factorial(int n) {
    int result = 1;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

int sumOfDigitFactorials(int n) {
    int sum = 0;
    while (n > 0) {
        int digit = n % 10;
        sum += factorial(digit);
        n /= 10;
    }
    return sum;
}

int main() {
    int N;
    cin >> N;

    long long sum = 0;

    for (int i = 10; i < N; ++i) {
        int digitFactorialSum = sumOfDigitFactorials(i);
        if (digitFactorialSum % i == 0) {
            sum += i;
        }
    }

    cout << sum << endl;
}
