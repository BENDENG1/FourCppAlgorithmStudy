#include <iostream>
#include <vector>
using namespace std;

int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N(0), K(0);
	cin >> N >> K;

	vector<vector<int>>board(N + 1, vector<int>(N + 1, -1));

	for (int idx = 0; idx < K; ++idx) {
		int y(0), x(0);
		cin >> y >> x;
		board[y][x] = -2;
	}

	int L(0);
	cin >> L;
	vector<pair<int, char>>info(L);

	for (int idx = 0; idx < L; ++idx) {
		int time(0);
		char dir(' ');
		cin >> time >> dir;
		info[idx] = { time,dir };
	}

	int y(1), x(1), time(0);
	pair<int, int>tail;
	tail.first = 1;
	tail.second = 1;

	int info_idx(0);

	int dir(1);
	board[1][1] = 1;
	while (1) {	
		if (info_idx < info.size() && info[info_idx].first == time) {
			if (info[info_idx].second == 'L') dir = (dir + 3) % 4;
			else if (info[info_idx].second == 'D') dir = (dir + 1) % 4;
			board[y][x] = dir;
			++info_idx;
		}
		++time;

		int next_y = y + dy[dir];
		int next_x = x + dx[dir];

		if (next_y < 1 || next_y > N || next_x < 1 || next_x > N || board[next_y][next_x]>=0) {
			cout << time;
			break;
		}		
		else if (board[next_y][next_x] == -1) {			
			int tailDir = board[tail.first][tail.second];
			board[tail.first][tail.second] = -1;
			tail.first = tail.first + dy[tailDir];
			tail.second = tail.second + dx[tailDir];			
		}		
		y = next_y;
		x = next_x;
		board[y][x] = dir;		
	}
}