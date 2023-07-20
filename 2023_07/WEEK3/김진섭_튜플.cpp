//문제풀이: https://githubseob.tistory.com/302

#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

bool cmp(pair<string, int> &p1, pair<string, int> &p2)
{
    return p1.second > p2.second;
}

vector<int> solution(string s)
{
    int idx(0);
    vector<int> answer;
    unordered_map<string, int> count;
    string number("");

    for (idx = 0; idx + 1 < s.size(); ++idx)
    {
        if (isdigit(s[idx]))
        {
            number += s[idx];
        }
        else if (!number.empty())
        {
            ++count[number];
            number.clear();
        }
    }
    vector<pair<string, int>> tuple(count.begin(), count.end());
    sort(tuple.begin(), tuple.end(), cmp);

    for (idx = 0; idx < tuple.size(); ++idx)
    {
        answer.push_back(stoi(tuple[idx].first));
    }

    return answer;
}