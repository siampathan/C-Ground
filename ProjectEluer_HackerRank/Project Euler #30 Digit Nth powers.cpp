#include <iostream>
#include <cmath>
using namespace std;

int calculate_sum_of_nth_power_digits(int num, int power) {
    int sum = 0;
    while (num > 0) {
        int digit = num % 10;
        sum += pow(digit, power);
        num /= 10;
    }
    return sum;
}

int main() {
    int N;
    cin >> N;

    int upper_limit = pow(9, N) * (N + 1); // Calculate the upper limit for the search
    int sum = 0;

    for (int num = 10; num <= upper_limit; num++) {
        if (num == calculate_sum_of_nth_power_digits(num, N)) {
            sum += num;
        }
    }

    cout << sum << endl;
}