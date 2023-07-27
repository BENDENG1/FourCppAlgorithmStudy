//문제풀이: https://githubseob.tistory.com/198

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>>dungeon;
vector<bool>visited;
int answer;

void DFS(int idx, int cnt, int fa) {
    if (idx == dungeon.size()) {
        answer = max(answer, cnt);
        return;
    }

    for (int idx2 = 0; idx2 < dungeon.size(); ++idx2) {
        if (visited[idx2] == true) continue;
        visited[idx2] = true;
        DFS(idx + 1, cnt, fa);
        visited[idx2] = false;
        if (fa >= dungeon[idx2][0]) {
            visited[idx2] = true;
            DFS(idx + 1, cnt + 1, fa - dungeon[idx2][1]);
            visited[idx2] = false;
        }

    }
}

int solution(int k, vector<vector<int>> dungeons) {
    dungeon = dungeons;
    visited = vector<bool>(dungeon.size(), false);
    DFS(0, 0, k);
    return answer;
}