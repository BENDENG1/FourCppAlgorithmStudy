//문제풀이: https://githubseob.tistory.com/183

#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount)
{
    int answer(0), idx(0), left(0), right(0);
    bool flag(true);

    map<string, int> want_list;
    map<string, int> purchase_list;

    for (idx = 0; idx < want.size(); ++idx)
    {
        want_list[want[idx]] = number[idx];
    }
    for (idx = 0; idx < 10 && idx < discount.size(); ++idx)
    {
        if (want_list.find(discount[idx]) != want_list.end())
        {
            ++purchase_list[discount[idx]];
        }
        flag = true;
        for (auto iter = want_list.begin(); iter != want_list.end(); ++iter)
        {
            if (iter->second > purchase_list[iter->first])
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            ++answer;
        }
    }

    left = -1;
    right = 9;

    while (right + 1 < discount.size())
    {
        ++left;
        ++right;
        if (want_list.find(discount[right]) != want_list.end())
        {
            ++purchase_list[discount[right]];
        }

        if (purchase_list[discount[left]] == 1)
        {
            purchase_list.erase(discount[left]);
        }
        else if (purchase_list[discount[left]] > 1)
        {
            --purchase_list[discount[left]];
        }

        flag = true;
        for (auto iter = want_list.begin(); iter != want_list.end(); ++iter)
        {
            if (iter->second > purchase_list[iter->first])
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            ++answer;
        }
    }

    return answer;
}