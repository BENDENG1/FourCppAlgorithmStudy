/*
게임

1 ~ 9 숫자 

되도록이면 오래 살아남게 하는데 무한대로 살아남을 수 있는거 
dfs하면 될듯 근데 dp에 값이랑 최댓값 해서 값 갱신 ㄱㄱ
*/
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int n, m;
int board[51][51];
int dp[51][51];
bool visited[51][51];
int answer = 0;
bool isLoop = false;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int dfs(int y, int x){
    if(x < 0 || y < 0 || y >= n || x >= m || board[y][x] == 0){
        return 0;
    }
    if(visited[y][x]){
        isLoop = true;
        return 0;
    }
    if(isLoop){
        return 0;
    }
    if(dp[y][x] != -1){
        return dp[y][x];
    }
    visited[y][x] = true;
    dp[y][x] = 0;
    for(int i = 0 ; i < 4; i++){
        int ny = y + (board[y][x] * dy[i]);
        int nx = x + (board[y][x] * dx[i]);
        dp[y][x] = max(dp[y][x], dfs(ny,nx) + 1);
    }
    visited[y][x] = false;
    return dp[y][x];
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);

    cin >> n >> m;

    memset(dp, -1, sizeof(dp));
    memset(visited, false, sizeof(visited));

    for(int i = 0 ; i < n; i++){
        string s;
        cin >> s;
        for(int j = 0 ; j < m; j++){
            if(s[j] == 'H'){
                board[i][j] = 0;
            }else{
                board[i][j] = s[j]- '0';
            }
        }
    }

    answer = dfs(0,0);
    if(isLoop){
        cout << -1;
    }else{
        cout << answer;
    }
}