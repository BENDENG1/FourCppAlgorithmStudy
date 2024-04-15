#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

struct Coord {
	int y;
	int x;
	int cnt;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N(0), M(0);
	cin >> N >> M;

	vector<vector<int>>maze(N, vector<int>(M, 0));

	for (int y = 0; y < N; ++y) {
		string num("");
		cin >> num;
		for (int x = 0; x < M; ++x) {
			maze[y][x] = num[x] - '0';
		}
	}

	queue<Coord>q;
	Coord coord;
	coord.y = 0, coord.x = 0, coord.cnt = 1;
	q.push(coord);

	vector<vector<bool>>visited(N, vector<bool>(M, false));
	while (!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;
		int cnt = q.front().cnt;
		q.pop();
		for (int idx = 0; idx < 4; ++idx) {
			int next_y = y + dy[idx];
			int next_x = x + dx[idx];
			if (next_y == N - 1 && next_x == M - 1) {
				cout << cnt + 1;
				return 0;
			}			
			if (next_y < 0 || next_y >= N || next_x < 0 || next_x >= M) continue;
			else if (visited[next_y][next_x] == true) continue;
			else if (maze[next_y][next_x] == 0) continue;
			visited[next_y][next_x] = true;			
			coord.y = next_y;
			coord.x = next_x;
			coord.cnt = cnt + 1;
			q.push(coord);
		}
	}
}