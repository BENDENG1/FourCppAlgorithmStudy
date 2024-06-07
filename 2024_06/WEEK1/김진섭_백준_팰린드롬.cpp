//문제풀이: https://githubseob.tistory.com/386

#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N(0), M(0);
	cin >> N;
	vector<int>seq(N + 1, 0);
	for (int idx = 1; idx <= N; ++idx)	cin >> seq[idx];
	cin >> M;

	vector<vector<bool>>isPalindrome(N + 1, vector<bool>(N + 1, false));

	for (int start = 1; start <= N; ++start) {
		int idx = 1;
		isPalindrome[start][start] = true;
		while (1 <= start - idx && start + idx <= N && seq[start - idx] == seq[start + idx]) {
			isPalindrome[start - idx][start + idx] = true;
			++idx;
		}
		if (start + 1 > N || seq[start] != seq[start + 1]) continue;
		isPalindrome[start][start + 1] = true;

		idx = 1;
		while (1 <= start - idx && start + idx + 1 <= N && seq[start - idx] == seq[start + idx + 1]) {
			isPalindrome[start - idx][start + idx + 1] = true;
			++idx;
		}
	}

	int start(0), end(0);
	for (int idx = 0; idx < M; ++idx) {
		cin >> start >> end;
		cout << isPalindrome[start][end] << '\n';
	}
}