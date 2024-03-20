/*
체육대회

dfs 끝

*/
#include <string>
#include <vector>

using namespace std;

vector<bool> visited(10,false);

int answer,sum = 0;

void dfs(const vector<vector<int>> &ability, int idx){
    
    if(idx == ability[0].size()){
        answer = answer < sum ? sum : answer;
        return;
    }
    
    for(int i = 0; i < ability.size(); i++){
        if(visited[i] == true)
            continue;
        visited[i] = true;
        sum += ability[i][idx];
        dfs(ability,idx + 1);
        sum -= ability[i][idx];
        visited[i] = false;
    }
}

int solution(vector<vector<int>> ability) {
    dfs(ability,0);
    
    return answer;
}