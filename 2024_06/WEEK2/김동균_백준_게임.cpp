//dfs max값
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int N, M, answer = 0;
int Map[50][50];
bool Visited[50][50] = { false, };
int Dp[50][50];

//위 오 아 왼
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

int DFS(int x, int y) {
	if (x < 0 || y < 0 || x >= N || y >= M || Map[x][y] == 0)
		return 0;

	if (Visited[x][y] == true) {
		cout << -1 << endl;
		return;
	}

	if (Dp[x][y] != -1)
		return Dp[x][y];

	Visited[x][y] = true;
	Dp[x][y] = 0;

	for (int i = 0; i < 4; i++) {

		int nx = x + (Map[x][y] * dx[i]);
		int ny = y + (Map[x][y] * dy[i]);

		Dp[x][y] = max(Dp[x][y], DFS(nx, ny) + 1);
	}

	Visited[x][y] = false;

	return Dp[x][y];

}
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;

		for (int j = 0; j < M; j++) {

			Dp[i][j] = -1;

			if (str.at(j) == 'H')
				Map[i][j] = 0;
			else
				Map[i][j] = str.at(j) - '0';

		}
	}
	answer = DFS(0, 0);
	cout << answer << endl;
	return 0;
}