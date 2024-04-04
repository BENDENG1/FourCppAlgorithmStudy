//문제풀이: https://githubseob.tistory.com/381

#include <iostream>
#include <vector>
#define INF 4501
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N(0), M(0);
	cin >> N >> M;

	vector<vector<int>>dist(N + 1, vector<int>(N + 1, INF));

	for (int cow = 0; cow <= N; ++cow) {
		dist[cow][cow] = 0;
	}

	int cow1(0), cow2(0);
	for (int idx = 0; idx < M; ++idx) {
		cin >> cow1 >> cow2;
		dist[cow1][cow2] = 1;
	}

	for (int mid = 1; mid <= N; ++mid) {
		for (cow1 = 1; cow1 <= N; ++cow1) {
			for (cow2 = 1; cow2 <= N; ++cow2) {
				dist[cow1][cow2] = min(dist[cow1][cow2], dist[cow1][mid] + dist[mid][cow2]);
			}
		}
	}

	int answer(0);
	for (cow1 = 1; cow1 <= N; ++cow1) {
		int count(0);
		for (cow2 = 1; cow2 <= N; ++cow2) {
			if (dist[cow1][cow2] != INF || dist[cow2][cow1] != INF) {
				++count;
			}
		}
		if (count == N) ++answer;
	}
	cout << answer;
}