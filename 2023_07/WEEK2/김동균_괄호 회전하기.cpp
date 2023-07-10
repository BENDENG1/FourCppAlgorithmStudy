#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(string s)
{
    int answer = 0;
    int n = s.size();

    for (int i = 0; i < n; i++)
    {
        stack<char> test;
        bool check = true;

        for (int j = 0; j < n; j++)
        {
            char ch = s[(i + j) % n];

            if (ch == '(' || ch == '{' || ch == '[')
            {
                test.push(ch);
            }
            else if (ch == ')' || ch == '}' || ch == ']')
            {
                if (test.empty())
                {
                    check = false;
                    break;
                }
                char top = test.top();
                test.pop();
                if ((ch == ')' && top != '(') ||
                    (ch == '}' && top != '{') ||
                    (ch == ']' && top != '['))
                {
                    check = false;
                    break;
                }
            }
        }

        if (check && test.empty())
        {
            answer++;
        }
    }

    return answer;
}