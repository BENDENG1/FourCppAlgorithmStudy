/*
무인도 여행

x또는 1~9사이 자연수 x는 바다 숫자는 무인도 상하좌우

*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


bool visited[100][100] = {false};
int num = 0;

void dfs(vector<string> maps,int y, int x);

vector<int> solution(vector<string> maps) {
    vector<int> answer;

    for(int i = 0 ; i < maps.size();i++){
        for(int j = 0 ;  j < maps[0].size();j++){
            if(maps[i][j] != 'X' && !visited[i][j]){
                num = maps[i][j] - '0';
                dfs(maps,i,j);
                answer.push_back(num);
            }
            visited[i][j] = true;
        }
    }
    if(answer.size() == 0)
        answer.push_back(-1);
    sort(answer.begin(),answer.end());
    return answer;
}


void dfs(vector<string> maps,int y, int x){
    int dy[4] = {0,0,1,-1};
    int dx[4] = {1,-1,0,0};
    
    visited[y][x] = true;
    for(int i = 0 ; i < 4;i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(0<= ny && ny < maps.size() && 0<= nx && nx < maps[0].size()){
            if(!visited[ny][nx] && maps[ny][nx] != 'X'){
                num += (maps[ny][nx] - '0');
                dfs(maps,ny,nx);
            }
        }
    }
}