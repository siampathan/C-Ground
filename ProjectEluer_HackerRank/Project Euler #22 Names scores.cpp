#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int calculateNameScore(const string& name) {
    int score = 0;
    for (char c : name) {
        score += (c - 'A' + 1); 
    }
    return score;
}

int main() {
    int N;
    cin >> N;

    vector<string> names(N);
    for (int i = 0; i < N; ++i) {
        cin >> names[i];
    }

    sort(names.begin(), names.end());

    int Q;
    cin >> Q;
    for (int i = 0; i < Q; ++i) {
        string query;
        cin >> query;

        int position = find(names.begin(), names.end(), query) - names.begin() + 1;
        int score = calculateNameScore(query) * position;

        cout << score << endl;
    }
}