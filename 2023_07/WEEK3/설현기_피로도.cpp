#include <string>
#include <vector>
#define MAX 8
using namespace std;

int answer = 0;
bool visited[MAX] = {0};

void dfs(int cnt, int k, vector<vector<int>> &dungeons){
    if(cnt > answer)
        answer = cnt;
    
    for(int i = 0; i < dungeons.size(); i++){
        if(!visited[i] && k >= dungeons[i][0]){
            visited[i] = true;
            dfs(cnt + 1, k - dungeons[i][1], dungeons);
            visited[i] = false;
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    dfs(0, k, dungeons);
    
    return answer;
}