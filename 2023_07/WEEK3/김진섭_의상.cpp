// 문제풀이: https://githubseob.tistory.com/301

#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(vector<vector<string>> clothes)
{
    int answer(1), idx(0), maximum(0);
    map<string, vector<string>> category;

    for (idx = 0; idx < clothes.size(); ++idx)
    {
        category[clothes[idx][1]].push_back({clothes[idx][0]});
    }

    for (auto iter = category.begin(); iter != category.end(); ++iter)
    {
        answer *= (iter->second.size() + 1);
    }

    return answer - 1;
}