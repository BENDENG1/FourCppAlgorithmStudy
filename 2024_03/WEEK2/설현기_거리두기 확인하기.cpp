#include <string>
#include <vector>
#include <cstring>

using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int N = 5;

int visit[5][5];

bool dfs(vector<string> &place, int x, int y, int cnt){
    if(cnt >= 3) return true; // 3칸 이상은 필요 x
    if(cnt > 0 && place[x][y] == 'P') return false; // 맨해튼 거리 내에 파티션 없이 사람 있으면 x
    
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(nx < 0 || nx >= N || ny < 0 || nx >= N || visit[nx][ny]) continue;
        if(place[nx][ny] == 'X') continue;
        
        visit[nx][ny] = 1;
        if(!dfs(place, nx, ny, cnt + 1)) return false;
        visit[nx][ny] = 0;
    }
    return true;
}
vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    for(int i = 0; i < N; i++){
        bool flag = true;
        for(int j = 0; j < N; j++){
            for(int k = 0; k < N; k++){
                if(places[i][j][k] == 'P'){ // 응시자를 탐색하면 그 지점을 기준으로 dfs 시작
                    memset(visit, 0, sizeof(visit));
                    visit[j][k] = 1;
                    if(!dfs(places[i], j, k, 0)){
                        flag = false;
                        break;
                    }
                }
            }
        }
        answer.push_back(flag);
    }
    
    return answer;
}