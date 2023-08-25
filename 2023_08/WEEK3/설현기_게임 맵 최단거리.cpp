#include<vector>
#include<queue>
using namespace std;

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    bool check[101][101] = {0};
    int cntMap[101][101] = {0};
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    int n = maps[0].size();
    int m = maps.size();
    queue<pair<int, int>> q;
    
    q.push(make_pair(0, 0));
    check[0][0] = true;
    cntMap[0][0] = 1;
    
    while(!q.empty()){
        int curX = q.front().first;
        int curY = q.front().second;
        
        q.pop();
        
        for(int i = 0; i < 4; i++){
            int nx = curX + dx[i];
            int ny = curY + dy[i];
            
            if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
            if(check[nx][ny]) continue;
            if(maps[nx][ny] == 0) continue;
            
            check[nx][ny] = true;
            q.push(make_pair(nx, ny));
            cntMap[nx][ny] = cntMap[curX][curY] + 1;
        }
    }
    
    if(!cntMap[m-1][n-1]) answer = -1;
    else answer = cntMap[m-1][n-1];
    
    return answer;
}