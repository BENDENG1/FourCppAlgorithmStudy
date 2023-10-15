#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int cnt = 0;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int m, n;
vector<string> map;

void dfs(int x, int y) {
    cnt += map[x][y] - '0';
    map[x][y] = 'X';
    
    for (int i = 0; i < 4; i++) {
        if (x + dx[i] >= 0 && x + dx[i] < m && y + dy[i] >= 0 && y + dy[i] < n && map[x + dx[i]][y + dy[i]] != 'X') {
                dfs(x + dx[i], y + dy[i]);
        }
    }
}

vector<int> solution(vector<string> maps) {
    map = maps;
    vector<int> answer;
    m = map.size();
    n = map[0].size();
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (map[i][j] != 'X') {
                dfs(i, j);
                answer.push_back(cnt);
                cnt = 0;
            }
        }
    }
    
    sort(answer.begin(), answer.end());
    
    if (answer.size() == 0)
        answer.push_back(-1);
    return answer;
}