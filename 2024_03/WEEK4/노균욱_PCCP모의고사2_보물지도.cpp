/*
보물 지도

bfs로 풀지 뭐

n이 가로 m이 세로
*/
#include <string>
#include <vector>
#include <queue>

using namespace std;

int dy[4] = {0,0,1,-1};
int dx[4] = {1,-1,0,0};

bool visited[1001][1001][2] = {false,}; // 뒤에 0은 그냥 방문 1은 점프 방문
int arr[1001][1001] = {0,};

struct board{
    int y;
    int x;
    int time;
    bool isJump;
};

bool isRange(int y, int x, int height,int width){
    return (y > 0 && y <= height && x > 0 && x <= width);
}

int solution(int n, int m, vector<vector<int>> hole) {
    queue<board> q;

    for(auto a : hole){
        arr[a[1]][a[0]] = 1;
    }
    
    visited[1][1][0] = true;
    q.push({1,1,0,false});
    
    while(!q.empty()){
        board b = q.front();
        q.pop();
        
        if(b.x == n && b.y == m){
            return b.time;
        }
        
        for(int i = 0 ; i < 4; i++){
            int ny = b.y + dy[i];
            int nx = b.x + dx[i];
            int jumpY = b.y + 2 * dy[i];
            int jumpX = b.x + 2 * dx[i];
            
            if(b.isJump){
                if(isRange(ny,nx,m,n) && !visited[ny][nx][1] && arr[ny][nx] == 0){
                    visited[ny][nx][1] = true;
                    q.push({ny, nx, b.time + 1, true});
                }
            }else{
                if(isRange(ny,nx,m,n) && !visited[ny][nx][0] && arr[ny][nx] == 0){
                    visited[ny][nx][0] = true;
                    q.push({ny,nx,b.time + 1, false});
                }
                if(isRange(jumpY,jumpX,m,n) && !visited[jumpY][jumpX][1] && arr[jumpY][jumpX] == 0){
                    visited[ny][nx][1] = true;
                    q.push({jumpY,jumpX,b.time + 1, true});
                }
            }
        }
    }
    
    return -1;
}