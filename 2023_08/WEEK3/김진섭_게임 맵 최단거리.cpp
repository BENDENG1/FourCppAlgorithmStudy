//문제풀이: https://githubseob.tistory.com/313

#include <vector>
#include <queue>
using namespace std;

struct Coord {
    int y;
    int x;
    int dist;
};

int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0,-1 };

int solution(vector<vector<int> > maps)
{
    int N = maps.size(), M = maps[0].size();
    vector<vector<bool>>visited(N, vector<bool>(M, false));
    queue<Coord>q;
    Coord start;
    start.y = 0, start.x = 0, start.dist = 1;
    q.push(start);
    visited[0][0] = true;

    while (!q.empty()) {
        int y = q.front().y;
        int x = q.front().x;
        int dist = q.front().dist;
        q.pop();

        for (int idx = 0; idx < 4; ++idx) {
            int ny = y + dy[idx];
            int nx = x + dx[idx];
            if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
            if (visited[ny][nx] == true) continue;
            if (ny == N - 1 && nx == M - 1) return dist + 1;
            if (maps[ny][nx] == 0) continue;
            visited[ny][nx] = true;
            Coord coord;
            coord.y = ny, coord.x = nx, coord.dist = dist + 1;
            q.push(coord);
        }
    }

    return -1;
}