//문제풀이: https://githubseob.tistory.com/378

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N(0);

	vector<bool>isPrime(246913, true);
	for (int idx = 2; idx <= sqrt(246912); ++idx) {
		for (int idx2 = 2; idx * idx2 <= 246912; ++idx2) {
			isPrime[idx * idx2] = false;
		}
	}

	vector<int>prime;
	for (int idx = 2; idx <= 246912; ++idx) {
		if (isPrime[idx] == true) {
			prime.push_back(idx);
		}
	}

	while (1) {
		cin >> N;
		if (N == 0) break;

		int N_left_idx(0), N_right_idx(0);
		N_left_idx = lower_bound(prime.begin(), prime.end(), N + 1) - prime.begin();
		N_right_idx = upper_bound(prime.begin(), prime.end(), 2 * N) - prime.begin();

		cout << N_right_idx - N_left_idx << '\n';
	}
}