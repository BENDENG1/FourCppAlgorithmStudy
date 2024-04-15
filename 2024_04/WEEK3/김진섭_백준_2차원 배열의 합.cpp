#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N(0), M(0);
	cin >> N >> M;
	vector<vector<int>>seq(N + 1, vector<int>(M + 1, 0));
	for (int y = 1; y <= N; ++y) {
		for (int x = 1; x <= M; ++x) {
			cin >> seq[y][x];
			seq[y][x] += seq[y][x - 1];
		}
	}
	for (int y = 1; y <= N; ++y) {
		for (int x = 1; x <= M; ++x) {
			seq[y][x] += seq[y - 1][x];
		}
	}
	
	int K(0);
	cin >> K;
	for (int idx = 0; idx < K; ++idx) {
		int start_y(0), start_x(0), end_x(0), end_y(0);
		cin >> start_y >> start_x >> end_y >> end_x;			
		cout << seq[end_y][end_x] - seq[end_y][start_x-1] - seq[start_y-1][end_x] + seq[start_y - 1][start_x - 1] <<'\n';
	}
}