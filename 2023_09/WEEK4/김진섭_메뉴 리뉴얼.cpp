//문제풀이: https://githubseob.tistory.com/187

#include <unordered_map>
#include <algorithm>
#include <string>
#include <vector>
#define psi pair<string, int>
using namespace std;

bool cmp(pair<string, int>& p1, pair<string, int>& p2) {
    return p1.second > p2.second;
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    vector<bool>CanMenu(11, false);
    unordered_map<string, int>menu_list;
    for (int idx = 0; idx < course.size(); ++idx) {
        CanMenu[course[idx]] = true;
    }

    for (int idx = 0; idx < orders.size(); ++idx) {
        for (int i = 1; i < (1 << orders[idx].size()); ++i) {
            string menu("");
            for (int j = 0; j < orders[idx].size(); ++j) {
                if (i & (1 << j)) menu += orders[idx][j];
            }
            sort(menu.begin(), menu.end());
            if (CanMenu[menu.size()] == true) {
                ++menu_list[menu];
            }
        }
    }

    vector<psi>menu_info(menu_list.begin(), menu_list.end());
    sort(menu_info.begin(), menu_info.end(), cmp);
    vector<int>cnt(11, 0);

    for (int idx = 0; idx < menu_info.size(); ++idx) {
        string menu_name = menu_info[idx].first;
        int menu_cnt = menu_info[idx].second;
        int menu_len = menu_name.size();

        if (menu_cnt == 1) continue;
        if (cnt[menu_len] == 0 || cnt[menu_len] == menu_cnt) {
            cnt[menu_len] = menu_cnt;
            answer.push_back(menu_name);
        }
    }

    sort(answer.begin(), answer.end());
    return answer;
}