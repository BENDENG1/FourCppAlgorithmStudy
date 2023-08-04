#include <string>
#include <vector>

using namespace std;

string trans(long long a, long long b)
{
    string s_num = "";

    while (a > 0)
    {
        int remainder = a % b;
        if (remainder >= 10)
        {
            char hexDigit = 'A' + remainder - 10;
            s_num = hexDigit + s_num;
        }
        else
        {
            s_num = to_string(remainder) + s_num;
        }
        a = a / b;
    }

    return s_num;
}

string solution(int n, int t, int m, int p)
{
    string answer = "";
    string a = "0";
    for (int i = 0; a.size() <= t * m; i++)
    {
        a += trans(i, n);
    }

    for (int i = p - 1; i < t * m; i += m)
    {
        answer += a[i];
    }

    return answer;
}