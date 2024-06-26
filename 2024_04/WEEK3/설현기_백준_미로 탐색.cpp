#include <iostream>
#include <queue>

using namespace std;

int main(){
    int n, m;
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    int maze[101][101];
    int visited[101][101];
    int dist[101][101];
    queue<pair<int, int>> q;
    
    cin >> n >> m;
    
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        for(int j = 0; j < m; j++){
             maze[i][j] = s[j] - '0'; 
        }
    }
    
    visited[0][0] = 1;
    q.push(make_pair(0, 0));
    dist[0][0]++;
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        
        q.pop();
        
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if ( (0 <= nx && nx < n) && (0 <= ny && ny < m) && !visited[nx][ny] && maze[nx][ny] == 1 ){
                visited[nx][ny] = 1;
                q.push(make_pair(nx, ny));
                dist[nx][ny] = dist[x][y] + 1;
            }
        }
    }
    
    cout << dist[n - 1][m - 1];
}