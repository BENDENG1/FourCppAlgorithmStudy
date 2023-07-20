// 문제풀이: https://githubseob.tistory.com/303

#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds)
{
    int day(0);
    vector<int> answer;
    queue<int> list;
    for (int idx = 0; idx < speeds.size(); ++idx)
    {
        if (progresses[idx] + speeds[idx] * day < 100)
        {
            if (!list.empty())
            {
                answer.push_back(list.size());
                while (!list.empty())
                {
                    list.pop();
                }
            }
            day = (100 - progresses[idx] + speeds[idx] - 1) / speeds[idx];
        }
        list.push(idx);
    }

    if (!list.empty())
    {
        answer.push_back(list.size());
    }
    return answer;
}