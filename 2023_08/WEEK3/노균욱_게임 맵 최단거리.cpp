#include <vector>
#include <queue>
using namespace std;

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    
    int dy[4] = {0,0,1,-1};
    int dx[4] = {1,-1,0,0};
    int distance[100][100] = {0,}; // 몇번재 방문했는지 -> 항상 최소 경로 횟수로 갱신이 됨
    queue<pair<int,int>> q;
    
    q.push({0,0});
    distance[0][0] = 1; //시작점인데 시작점도 1로 침
    
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        
        q.pop();
        for(int i = 0; i < 4;i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            //범위 안에 있고 방문하지 않고 갈 수 있는 경우 체크
            if(0 <= ny && ny < maps.size() && 0 <= nx && nx <maps[0].size() 
               && maps[ny][nx] == 1 && distance[ny][nx] == 0 ){
                q.push({ny,nx});
                distance[ny][nx] = distance[y][x] + 1;
                if(ny == maps.size() - 1 && nx == maps[0].size() - 1)
                    return distance[ny][nx];
            }
        }
    }
    return -1;
}