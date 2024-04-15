#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int dx[4] = { 1,0,-1,0 }; // x좌표 이동
int dy[4] = { 0,1,0,-1 }; // y좌표 이동

int N, M;
int Dist[101][101]; // 거리를 저장할 배열
char Map[101][101]; // 미로를 만들 배열
int visited[101][101]; // 방문한 위치를 표시할 배열

void BFS(int X, int Y) {
    visited[X][Y] = 1;

    queue<pair<int, int>> Q;
    Q.push(make_pair(X, Y));

    while (!Q.empty()) {
        int x = Q.front().first;
        int y = Q.front().second;

        Q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
                if (Map[nx][ny] == '1' && visited[nx][ny] == 0) {
                    Dist[nx][ny] = Dist[x][y] + 1;
                    // 다음 위치로 이동
                    visited[nx][ny] = 1;
                    // 방문했음 처리
                    Q.push(make_pair(nx, ny));
                    // 큐에 집어 넣어서 다음 좌표에서 BFS 시작
                }
            }
        }

    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> Map[i];
    }
    BFS(0, 0);
    cout << Dist[N - 1][M - 1] + 1 << '\n'; // 미로의 끝지점에서의 거리 출력
    return 0;
}