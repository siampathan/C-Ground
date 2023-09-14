#include <iostream>
#include <vector>
#include <string>
using namespace std;

string below_20[] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
string tens[] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
string thousands[] = {"", "Thousand", "Million", "Billion"};

string convert_to_words(int num) {
    if (num < 20) {
        return below_20[num];
    } else if (num < 100) {
        return tens[num / 10] + (num % 10 != 0 ? " " + below_20[num % 10] : "");
    } else {
        return below_20[num / 100] + " Hundred" + (num % 100 != 0 ? " " + convert_to_words(num % 100) : "");
    }
}

string number_to_words(long long n) {
    if (n == 0) {
        return "Zero";
    }

    vector<string> parts;
    int part_idx = 0;

    while (n > 0) {
        if (n % 1000 != 0) {
            parts.push_back(convert_to_words(n % 1000) + (thousands[part_idx] != "" ? " " + thousands[part_idx] : ""));
        }
        n /= 1000;
        part_idx++;
    }

    string result = parts.back();
    for (int i = parts.size() - 2; i >= 0; i--) {
        result += " " + parts[i];
    }

    return result;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        long long N;
        cin >> N;
        cout << number_to_words(N) << endl;
    }

    return 0;
}