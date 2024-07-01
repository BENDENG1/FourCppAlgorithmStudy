#include <iostream>
using namespace std;

int main() {
	int T(0), N(0);
	cin >> T;

	int DP[41][2];

	DP[0][0] = 1;
	DP[0][1] = 0;

	for (N = 1; N <= 40; ++N) {
		DP[N][0] = DP[N - 1][1];
		DP[N][1] = DP[N - 1][0] + DP[N - 1][1];
	}

	for (int test_case = 1; test_case <= T; ++test_case) {
		cin >> N;
		cout << DP[N][0] << " " << DP[N][1] << '\n';
	}
}