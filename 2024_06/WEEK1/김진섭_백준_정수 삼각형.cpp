//문제풀이: https://githubseob.tistory.com/385

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N(0);
	cin >> N;

	vector<vector<int>>triangle(N + 1, vector<int>(N + 1, 0));
	vector<vector<int>>DP(N + 1, vector<int>(N + 1, 0));

	for (int y = 1; y <= N; ++y) {
		for (int x = 1; x <= y; ++x) {
			cin >> triangle[y][x];
		}
	}

	for (int y = 1; y <= N; ++y) {
		for (int x = 1; x <= y; ++x) {
			DP[y][x] = triangle[y][x] + max(DP[y - 1][x - 1], DP[y - 1][x]);
		}
	}

	int answer(0);
	for (int x = 1; x <= N; ++x) {
		answer = max(answer, DP[N][x]);
	}

	cout << answer;
}