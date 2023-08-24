//문제풀이: https://githubseob.tistory.com/314

#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer(0);

    vector<int>alp(26, -1);

    for (int idx = 0; idx < skill.size(); ++idx) {
        alp[skill[idx] - 'A'] = idx;
    }

    for (int idx = 0; idx < skill_trees.size(); ++idx) {
        int s_idx(0);
        bool flag(true);
        for (int s_cnt = 0; s_cnt < skill_trees[idx].size(); ++s_cnt) {
            char c = skill_trees[idx][s_cnt] - 'A';
            if (alp[c] == -1) continue;
            else if (alp[c] == s_idx)  ++s_idx;
            else if (alp[c] != s_idx) {
                flag = false;
                break;
            }
        }
        if (flag == true) ++answer;
    }

    return answer;
}