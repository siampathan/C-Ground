#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

bool isPandigital(int multiplicand, int multiplier, int product, int N) {
    vector<int> digits;
    while (multiplicand > 0) {
        digits.push_back(multiplicand % 10);
        multiplicand /= 10;
    }
    while (multiplier > 0) {
        digits.push_back(multiplier % 10);
        multiplier /= 10;
    }
    while (product > 0) {
        digits.push_back(product % 10);
        product /= 10;
    }

    if (digits.size() != N) {
        return false;
    }

    sort(digits.begin(), digits.end());
    for (int i = 1; i <= N; ++i) {
        if (digits[i - 1] != i) {
            return false;
        }
    }

    return true;
}

int main() {
    int N;
    cin >> N;

    set<int> products;

    vector<int> digits;
    for (int i = 1; i <= N; ++i) {
        digits.push_back(i);
    }

    do {
        for (int i = 1; i < N - 1; ++i) {
            for (int j = i + 1; j < N; ++j) {
                int multiplicand = 0;
                int multiplier = 0;
                int product = 0;

                for (int k = 0; k < i; ++k) {
                    multiplicand = multiplicand * 10 + digits[k];
                }

                for (int k = i; k < j; ++k) {
                    multiplier = multiplier * 10 + digits[k];
                }

                for (int k = j; k < N; ++k) {
                    product = product * 10 + digits[k];
                }

                if (multiplicand * multiplier == product) {
                    products.insert(product);
                }
            }
        }
    } while (next_permutation(digits.begin(), digits.end()));

    int sum = 0;
    for (int product : products) {
        sum += product;
    }

    cout << sum << endl;
}