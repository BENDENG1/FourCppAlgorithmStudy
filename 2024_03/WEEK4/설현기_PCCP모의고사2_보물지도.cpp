#include <string>
#include <vector>
#include <queue>
using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int board[1001][1001];
bool visited[1001][1001][2];

int solution(int n, int m, vector<vector<int>> hole) {
    int answer = -1;
    for(auto a : hole){
        int x = a[0];
        int y = a[1];
        board[x][y] = 1;
    }
    queue<vector<int>> q;
    q.push({1, 1, 0, 0});
    while(!q.empty()){
        int x, y, used, dist;
        vector<int> cur = q.front();
        q.pop();
        x = cur[0];
        y = cur[1];
        used = cur[2];
        dist = cur[3];
        if(x == n && y == m){
            answer = dist;
            break;
        }
        if(x < 1 || x > n || y < 1 || y > m || visited[x][y][used] || board[x][y])
            continue;
        visited[x][y][used] = true;
        for(int i = 0; i < 4; i++){
            q.push({x + dx[i], y + dy[i], used, dist + 1});
            if(used == 0){
                q.push({x + dx[i] * 2, y + dy[i] * 2, 1, dist + 1});
            }
        }
    }
    return answer;
}