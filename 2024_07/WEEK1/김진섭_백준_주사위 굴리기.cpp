#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int dy[4] = { 0,0,-1,1 };
int dx[4] = { 1,-1,0,0 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N(0), M(0);
	cin >> N >> M;
	vector<vector<int>>map(N, vector<int>(M, 0));

	int diceY(0), diceX(0);
	cin >> diceY >> diceX;
	int K(0);
	cin >> K;

	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			cin >> map[y][x];
		}
	}
	
	vector<int>dice(6, 0);
	int y = diceY;
	int x = diceX;

	int cmd(0);
	for (int idx = 0; idx < K; ++idx) {
		cin >> cmd;
		int next_y = y + dy[cmd - 1];
		int next_x = x + dx[cmd - 1];

		if (next_y < 0 || next_y >= N || next_x < 0 || next_x >= M) continue;

		if (cmd == 1) {
			swap(dice[1], dice[4]);
			swap(dice[1], dice[3]);
			swap(dice[1], dice[5]);
		}
		else if (cmd == 2) {
			swap(dice[1], dice[5]);
			swap(dice[3], dice[4]);
			swap(dice[1], dice[3]);
		}
		else if (cmd == 3) {
			swap(dice[3], dice[2]);
			swap(dice[2], dice[1]);
			swap(dice[1], dice[0]);
		}
		else if (cmd == 4) {
			swap(dice[0], dice[1]);
			swap(dice[1], dice[2]);
			swap(dice[2], dice[3]);
		}
		y = next_y;
		x = next_x;

		if (map[y][x] == 0) map[y][x] = dice[1];
		else if (map[y][x] != 0) {
			dice[1] = map[y][x];
			map[y][x] = 0;
		}

		cout << dice[3] << '\n';
	}
}