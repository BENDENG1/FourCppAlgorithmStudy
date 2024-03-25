//문제풀이: https://githubseob.tistory.com/376

#include <string>
#include <vector>
#include <queue>
#define INF 1e7
using namespace std;

int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,-1,1 };

struct Coord {
    int y;
    int x;
    bool used_shoes;
};

int solution(int n, int m, vector<vector<int>> hole) {
    int answer = 0;
    vector<vector<vector<int>>>dist(m + 1, vector<vector<int>>(n + 1, vector<int>(2, INF)));
    vector<vector<bool>>map(m + 1, vector<bool>(n + 1, false));
    queue<Coord>q;

    for (int idx = 0; idx < hole.size(); ++idx) {
        int y = hole[idx][1];
        int x = hole[idx][0];
        map[y][x] = true; // 벽 감지
    }

    Coord coord;
    coord.y = 1, coord.x = 1, coord.used_shoes = false;
    q.push(coord);
    dist[1][1][0] = 0;
    dist[1][1][1] = 0;

    while (!q.empty()) {
        int y = q.front().y;
        int x = q.front().x;
        bool used_shoes = q.front().used_shoes;
        q.pop();

        for (int idx = 0; idx < 4; ++idx) {
            int next_y = y + dy[idx];
            int next_x = x + dx[idx];
            if (next_y < 1 || next_y > m || next_x < 1 || next_x > n) continue;
            if (dist[next_y][next_x][used_shoes] != INF) continue;
            if (map[next_y][next_x] == false) {
                if (dist[y][x][used_shoes] + 1 < dist[next_y][next_x][used_shoes]) {
                    dist[next_y][next_x][used_shoes] = dist[y][x][used_shoes] + 1;
                    coord.y = next_y, coord.x = next_x, coord.used_shoes = used_shoes;
                    q.push(coord);
                }
            }
            else if (map[next_y][next_x] == true) {
                if (used_shoes == true) continue;
                else if (used_shoes == false) {
                    int jump_y = next_y + dy[idx];
                    int jump_x = next_x + dx[idx];
                    if (jump_y < 1 || jump_y > m || jump_x < 1 || jump_x > n) continue;
                    if (map[jump_y][jump_x] == true) continue;
                    if (dist[jump_y][jump_x][true] != INF) continue;
                    if (dist[y][x][false] + 1 < dist[jump_y][jump_x][true]) {
                        dist[jump_y][jump_x][true] = dist[y][x][false] + 1;
                        coord.y = jump_y, coord.x = jump_x, coord.used_shoes = true;
                        q.push(coord);
                    }
                }
            }
        }
    }

    answer = min(dist[m][n][0], dist[m][n][1]);
    if (answer == INF) answer = -1;
    return answer;
}