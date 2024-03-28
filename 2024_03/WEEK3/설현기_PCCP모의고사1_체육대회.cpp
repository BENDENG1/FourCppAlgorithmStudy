#include <string>
#include <vector>

using namespace std;

int visit[10] = {0,};
int max_ = 0;
int sum = 0;

void dfs(vector<vector<int>> &ability, int index){
    
    if (index == ability[0].size()){ // 한 경우를 다 찾았으면 합산
        if (max_ < sum)
            max_ = sum;
        return ;
    }
    
    for (int i = 0; i<ability.size(); i++){
        if (visit[i] == 1)
            continue;
        visit[i] = 1;
        sum += ability[i][index];
        dfs(ability,index+1);
        sum -= ability[i][index];
        visit[i] = 0;
    }
}

int solution(vector<vector<int>> ability) {
    int answer = 0;
    
    dfs(ability, 0);
    answer = max_;
    
    return answer;
}