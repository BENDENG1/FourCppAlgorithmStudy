#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int k, vector<vector<int>> dungeons)
{
    int n = dungeons.size();
    int answer = 0;

    // 행의 순서를 저장하는 인덱스 배열
    vector<int> indices(n);
    for (int i = 0; i < n; ++i)
    {
        indices[i] = i;
    }

    do
    {
        int currentK = k;
        int currentAnswer = 0;

        for (int i = 0; i < n; ++i)
        {
            int idx = indices[i];
            if (currentK >= dungeons[idx][0])
            {
                currentAnswer++;
                currentK -= dungeons[idx][1];
            }
        }

        // 모든 조합 중 최대 조합 개수 구하기
        answer = max(answer, currentAnswer);

    } while (next_permutation(indices.begin(), indices.end()));
    return answer;
}