//문제풀이: https://githubseob.tistory.com/348

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
vector<vector<bool>>visited;
vector<string>maps;
vector<int> answer;
int N, M, max_day;

void DFS(int y, int x) {
    for (int idx = 0; idx < 4; ++idx) {
        int ny = y + dy[idx];
        int nx = x + dx[idx];
        if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
        if (visited[ny][nx] == true) continue;
        visited[ny][nx] = true;
        max_day += maps[ny][nx] - '0';
        DFS(ny, nx);
    }
}

vector<int> solution(vector<string> maps) {
    ::maps = maps;
    N = maps.size();
    M = maps[0].size();

    visited = vector<vector<bool>>(N, vector<bool>(M, false));
    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < M; ++x) {
            if (maps[y][x] == 'X') visited[y][x] = true;
        }
    }

    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < M; ++x) {
            if (visited[y][x] == false) {
                visited[y][x] = true;
                max_day = maps[y][x] - '0';
                DFS(y, x);
                answer.push_back(max_day);
            }
        }
    }
    if (answer.empty()) answer.push_back(-1);
    else sort(answer.begin(), answer.end());

    return answer;
}