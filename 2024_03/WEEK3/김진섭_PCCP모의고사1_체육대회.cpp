//문제풀이: https://githubseob.tistory.com/371

#include <string>
#include <vector>
#include <algorithm>
#define pii pair<int, int>
using namespace std;
vector<vector<pii>>ab;
vector<bool>visited;
int answer;
int sport_cnt;

void DFS(int sport, int score, vector<bool>visited) {
    if (sport == ab[0].size()) answer = max(answer, score);
    else {
        for (int idx = 0; idx < sport_cnt; ++idx) {
            int student = ab[idx][sport].second;
            if (visited[student]) continue;
            visited[student] = true;
            DFS(sport + 1, score + ab[idx][sport].first, visited);
            visited[student] = false;
        }
    }
}

int solution(vector<vector<int>> ability) {
    sport_cnt = ability[0].size();
    ab = vector<vector<pii>>(sport_cnt, vector<pii>(sport_cnt, { 0,0 }));
    visited = vector<bool>(ability.size(), false);

    for (int sport = 0; sport < sport_cnt; ++sport) {
        vector<pii>scores(ability.size());
        for (int student = 0; student < scores.size(); ++student) {
            scores[student] = { ability[student][sport], student };
        }

        sort(scores.begin(), scores.end(), greater<pii>());
        for (int student = 0; student < sport_cnt; ++student) {
            ab[student][sport] = scores[student];
        }
    }

    for (int student = 0; student < sport_cnt; ++student) {
        visited[ab[student][0].second] = true;
        DFS(1, ab[student][0].first, visited);
        visited[ab[student][0].second] = false;
    }

    return answer;
}