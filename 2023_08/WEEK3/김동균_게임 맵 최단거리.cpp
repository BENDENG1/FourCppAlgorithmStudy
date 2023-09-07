#include <vector>
#include <queue>
using namespace std;

int dirX[] = {1, -1, 0, 0};  // 행 방향 변화량 (x-좌표)
int dirY[] = {0, 0, 1, -1};  // 열 방향 변화량 (y-좌표)

int solution(vector<vector<int>> maps) {
    int n = maps.size();  // 미로의 행 개수
    int m = maps[0].size();  // 미로의 열 개수

    queue<pair<int, int>> q;  // BFS에 사용할 큐
    q.push({0, 0});  // 시작 지점을 큐에 넣음

    int answer = 1;  // 경로 길이 초기화

    while (!q.empty()) {
        int qSize = q.size();  // 현재 큐에 들어있는 지점의 개수

        for (int i = 0; i < qSize; ++i) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            if (row == n - 1 && col == m - 1) {
                return answer;  // 목적지에 도달한 경우 경로 길이 반환
            }

            for (int j = 0; j < 4; ++j) {
                int newRow = row + dirX[j];
                int newCol = col + dirY[j];

                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && maps[newRow][newCol] == 1) {
                    q.push({newRow, newCol});
                    maps[newRow][newCol] = 0;  // 방문한 지점으로 표시
                }
            }
        }

        answer++;  // 경로 길이 증가
    }

    return -1;  // 목적지에 도달하지 못한 경우 -1 반환
}