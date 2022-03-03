#include<iostream>
using namespace std;

int max(int a, int b) { return (a > b) ? a : b; }

int knapSack(int W, int wt[], int val[], int n) {
	if (n == 0 || W == 0)
		return 0;

	if (wt[n - 1] > W)
		return knapSack(W, wt, val, n - 1);
	else
		return max(val[n - 1] + knapSack(W - wt[n - 1],
			wt, val, n - 1), knapSack(W, wt, val, n - 1));
}

int main() {
	int val[] = { 10,10,12,18 };
	int wt[] = { 2,4,6,9 };
	int m = 15;
	int n = sizeof(val) / sizeof(val[0]);
	cout << knapSack(m, wt, val, n);
	return 0;
}
