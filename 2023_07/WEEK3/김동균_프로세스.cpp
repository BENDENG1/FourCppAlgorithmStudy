#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location)
{
    int answer = 0;

    while (!priorities.empty())
    {
        int t = priorities.front();
        priorities.erase(priorities.begin());

        if (any_of(priorities.begin(), priorities.end(), [t](int i)
                   { return i > t; }))
        {
            priorities.push_back(t);
            if (location == 0)
            {
                location = priorities.size() - 1;
            }
            else
            {
                location--;
            }
        }
        else
        {
            answer++;
            if (location == 0)
            {
                break;
            }
            location--;
        }
    }

    return answer;
}