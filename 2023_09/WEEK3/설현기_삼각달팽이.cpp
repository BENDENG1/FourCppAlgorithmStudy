#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n)
{
    vector<vector<int>> v(n + 1, vector<int>(n + 1));
    vector<int> answer;

    int max_num = (n * (n + 1)) / 2;
    int top = 1;
    int bottom = n;
    int left = 1;
    int right = 0;
    int num = 1;
    int state = 0;

    while (num <= max_num)
    {
        for (int i = top; i <= bottom; i++)
            v[i][left] = num++;
        top++;
        left++;

        for (int i = left; i <= bottom - right; i++)
            v[bottom][i] = num++;
        bottom--;

        for (int i = bottom; i >= top; i--)
            v[i][i - right] = num++;
        right++;
        top++;
    }
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            answer.push_back(v[i][j]);
        }
    }
    return answer;
}