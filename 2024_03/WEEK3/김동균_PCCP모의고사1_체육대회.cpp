#include <vector>
#include <algorithm>

using namespace std;

int answer = 0;

void backtrack(const vector<vector<int>>& ability, int n, vector<int>& team, vector<bool>& visited, int sum) {
    if (n == ability[0].size()) {
        answer = max(answer, sum);
        return;
    }
    
    for (int i = 0; i < ability.size(); i++) {
        if (!visited[i]) {
            visited[i] = true;
            team.push_back(i);
            backtrack(ability, n + 1, team, visited, sum + ability[i][n]);
            team.pop_back();
            visited[i] = false;
        }
    }
}

int solution(vector<vector<int>> ability) {
    int n = ability[0].size();
    vector<int> team;
    vector<bool> visited(ability.size(), false);
    backtrack(ability, 0, team, visited, 0);
    return answer;
}

