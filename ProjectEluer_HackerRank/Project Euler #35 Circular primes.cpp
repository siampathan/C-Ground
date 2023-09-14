#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool is_prime(int num) {
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

bool are_all_rotations_prime(int num) {
    int digits = log10(num) + 1;

    for (int i = 0; i < digits; i++) {
        if (!is_prime(num)) {
            return false;
        }

        int last_digit = num % 10;
        num = num / 10 + last_digit * pow(10, digits - 1);
    }

    return true;
}

int sum_of_circular_primes(int N) {
    int sum = 0;
    for (int i = 2; i < N; i++) {
        if (are_all_rotations_prime(i)) {
            sum += i;
        }
    }
    return sum;
}

int main() {
    int N;
    cin >> N;
    
    int result = sum_of_circular_primes(N);
    cout << result << endl;
}