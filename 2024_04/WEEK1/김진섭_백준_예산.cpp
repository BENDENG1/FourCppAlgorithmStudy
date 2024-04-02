//문제풀이: https://githubseob.tistory.com/48

#include <iostream>
#include <vector>
#define MAX_budget 1e9
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N(0), M(0);
	int sum(0), max_budget(0);

	cin >> N;
	vector<int>budget(N, 0);

	for (int idx = 0; idx < N; ++idx) {
		cin >> budget[idx];
		sum += budget[idx];
		max_budget = max(max_budget, budget[idx]);
	}
	cin >> M;

	if (sum <= M) {
		cout << max_budget;
	}
	else {
		int left(0), right(MAX_budget);
		while (left <= right) {
			int mid((left + right) / 2);
			int sum(0);
			for (int idx = 0; idx < N; ++idx) {
				sum += min(budget[idx], mid);
			}
			if (sum > M) {
				right = mid - 1;
			}
			else if (sum <= M) {
				left = mid + 1;
			}
		}
		cout << right;
	}
}