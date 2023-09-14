#include <iostream>

int main() {
    int T;
    std::cin >> T;

    while (T--) {
        int N;
        std::cin >> N;

        long long sum_of_squares = 0;
        for (int i = 1; i <= N; ++i) {
            sum_of_squares += i * i;
        }

        long long sum = (N * (N + 1)) / 2;
        long long square_of_sum = sum * sum;

        long long absolute_difference = square_of_sum - sum_of_squares;
        std::cout << absolute_difference << std::endl;
    }

}