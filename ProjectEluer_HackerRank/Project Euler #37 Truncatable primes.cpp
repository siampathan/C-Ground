#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }
    if (num <= 3) {
        return true;
    }
    if (num % 2 == 0 || num % 3 == 0) {
        return false;
    }

    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

bool isTruncatablePrime(int num) {
    if (!isPrime(num)) {
        return false;
    }

    int temp = num;
    int base = 1;
    while (temp > 0) {
        if (!isPrime(temp)) {
            return false;
        }
        temp /= 10;
        base *= 10;
    }

    temp = num;
    while (temp > 0) {
        if (!isPrime(temp)) {
            return false;
        }
        temp %= base;
        base /= 10;
    }

    return true;
}

int main() {
    int N;
    cin >> N;

    long long sum = 0;
    for (int i = 11; i < N; ++i) {
        if (isTruncatablePrime(i)) {
            sum += i;
        }
    }

    cout << sum << endl;

    return 0;
}