#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2)
{
    int n = arr1.size();    // 행렬 arr1의 행 개수
    int m = arr2[0].size(); // 행렬 arr2의 열 개수
    int l = arr2.size();    // 행렬 arr2의 행 개수 (arr1의 열 개수와 같아야 함)

    vector<vector<int>> answer(n, vector<int>(m, 0)); // 결과를 저장할 answer 행렬

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int k = 0; k < l; k++)
            {
                answer[i][j] += arr1[i][k] * arr2[k][j]; // 행렬의 곱셈 수행
            }
        }
    }

    return answer;
}