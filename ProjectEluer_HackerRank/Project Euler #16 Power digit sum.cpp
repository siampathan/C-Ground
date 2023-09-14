#include <iostream>
#include <vector>
using namespace std;

vector<int> multiply(vector<int> &digits, int multiplier) {
    int carry = 0;
    for (int i = 0; i < digits.size(); i++) {
        int product = digits[i] * multiplier + carry;
        digits[i] = product % 10;
        carry = product / 10;
    }

    while (carry) {
        digits.push_back(carry % 10);
        carry /= 10;
    }

    return digits;
}

int calculate_sum_of_digits(int power) {
    vector<int> digits;
    digits.push_back(1);

    for (int i = 0; i < power; i++) {
        multiply(digits, 2);
    }

    int sum = 0;
    for (int digit : digits) {
        sum += digit;
    }

    return sum;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;
        cout << calculate_sum_of_digits(N) << endl;
    }
}