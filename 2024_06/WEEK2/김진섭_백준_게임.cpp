#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

int N, M, answer;

void DFS(vector<vector<int>>&moveCnt, vector<vector<bool>>& visited, const vector<vector<int>>& board, int y, int x) {			
	if (answer == -1) return;

	for (int idx = 0; idx < 4; ++idx) {
		int ny = y + dy[idx] * board[y][x];
		int nx = x + dx[idx] * board[y][x];
		if (answer == -1) continue;
		if (ny < 0 || ny >= N || nx < 0 || nx >= M || board[ny][nx] == -1) {			
			continue;
		}
		if (moveCnt[ny][nx] >= moveCnt[y][x] + 1) {			
			continue;
		}
		
		moveCnt[ny][nx] = moveCnt[y][x] + 1;
		if (visited[ny][nx]) {
			answer = -1;
			return;
		}		
		answer = max(answer, moveCnt[ny][nx]);

		visited[ny][nx] = true;
		DFS(moveCnt, visited, board, ny, nx);
		visited[ny][nx] = false;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	vector<vector<int>>board(N, vector<int>(M, 0));

	string input("");
	for (int y = 0; y < N; ++y) {
		cin >> input;
		for (int x = 0; x < input.size(); ++x) {
			if (input[x] == 'H') board[y][x] = -1;
			else board[y][x] = input[x] - '0';
		}
	}

	vector<vector<bool>>visited(N, vector<bool>(M, false));
	vector<vector<int>>moveCnt(N, vector<int>(M, 0));	

	moveCnt[0][0] = 1;
	answer = 1;
	DFS(moveCnt, visited, board, 0, 0);

	cout << answer;
}