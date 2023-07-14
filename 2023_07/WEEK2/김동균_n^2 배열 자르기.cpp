#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right)
{
    vector<int> answer;

    for (long long i = left; i <= right; i++)
    {
        int row = i / n; // 현재 값 행
        int col = i % n; // 현재 값의 열

        // answer에 추가
        if (row <= col)
            answer.push_back(col + 1);
        else
            answer.push_back(row + 1);
    }

    return answer;
}