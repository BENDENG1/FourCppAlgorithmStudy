//문제풀이: https://githubseob.tistory.com/310

#include <vector>
#include <algorithm>
using namespace std;

int get_max(int num1, int num2, int num3) {
    return max(num1, max(num2, num3));
}

int solution(vector<vector<int>>land)
{
    int answer(0);
    vector<vector<int>>DP(land.size(), vector<int>(4));

    for (int x = 0; x < 4; ++x) DP[0][x] = land[0][x];

    for (int y = 1; y < DP.size(); ++y) {
        DP[y][0] = get_max(DP[y - 1][1], DP[y - 1][2], DP[y - 1][3]) + land[y][0];
        DP[y][1] = get_max(DP[y - 1][0], DP[y - 1][2], DP[y - 1][3]) + land[y][1];
        DP[y][2] = get_max(DP[y - 1][0], DP[y - 1][1], DP[y - 1][3]) + land[y][2];
        DP[y][3] = get_max(DP[y - 1][0], DP[y - 1][1], DP[y - 1][2]) + land[y][3];
    }
    for (int x = 0; x < 4; ++x) {
        answer = max(answer, DP[DP.size() - 1][x]);
    }
    return answer;
}