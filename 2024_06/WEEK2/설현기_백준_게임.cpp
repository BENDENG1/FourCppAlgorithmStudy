#include <iostream>
#include <string>
#include <algorithm>
#define MAX 51
using namespace std;

int N, M;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int answer;

int map[MAX][MAX];
int dp[MAX][MAX];
bool visited[MAX][MAX];
bool infinite = false;

int dfs(int x, int y){
    if (visited[x][y]) {
        infinite = true; // exit(0)
        return 0;
    }

    if (dp[x][y] != -1) {
        return dp[x][y];
    }
    
    visited[x][y] = true;
    dp[x][y] = 1;

    for (int i = 0; i < 4; i++) {
        int nx = map[x][y] * dx[i] + x;
        int ny = map[x][y] * dy[i] + y;

        if (nx < 0 || ny < 0 || nx >= N || ny >= M || map[nx][ny] == -1)
            continue;

        dp[x][y] = max(dp[x][y], dfs(nx, ny) + 1);
    }

    visited[x][y] = false;
    return dp[x][y];
}

int main(){
    string s;
    cin >> N >> M;
    
    for(int i = 0; i < N; i++){
        cin >> s;
        for(int j = 0; j < M; j++){
            if(s[j] == 'H')
                map[i][j] = -1;
            else
                map[i][j] = s[j] - '0';
        }
        
        for (int j = 0; j < M; j++) {
            dp[i][j] = -1;
        }
    }
    
    answer = dfs(0, 0);

    if (infinite)
        cout << -1;
    else
        cout << answer;
}
