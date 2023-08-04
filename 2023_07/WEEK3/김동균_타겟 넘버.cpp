#include <string>
#include <vector>

using namespace std;

void dfs(int n, int sum, vector<int> numbers, int target, int &answer)
{
    if (n == numbers.size())
    {
        if (sum == target)
            answer++;
        return;
    }
    dfs(n + 1, sum + numbers[n], numbers, target, answer);
    dfs(n + 1, sum - numbers[n], numbers, target, answer);
}

int solution(vector<int> numbers, int target)
{
    int answer = 0;
    dfs(0, 0, numbers, target, answer);
    return answer;
}