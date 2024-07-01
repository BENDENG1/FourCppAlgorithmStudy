#include <iostream>
#define ll long long
using namespace std;

int main() {
	int T(0);
	cin >> T;
	ll P[101];

	P[1] = P[2] = P[3] = 1;

	int N(0);

	for (N = 4; N <= 100; ++N) {
		P[N] = P[N - 3] + P[N - 2];
	}
	for (int test_case = 1; test_case <= T; ++test_case) {
		cin >> N;
		cout << P[N] << '\n';
	}
}