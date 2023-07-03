//문제풀이: https://githubseob.tistory.com/252

#include <string>
#include <vector>
#define DIV 1234567
using namespace std;

int solution(int n) { //재귀 싫어서 DP로
    int answer(0), idx(0);
    vector<int>DP(n + 1, 0);
    DP[1] = 1;
    DP[2] = 1;
    for (idx = 3; idx <= n; ++idx) {
        DP[idx] = (DP[idx - 1] + DP[idx - 2]) % DIV;
        // 문제 조건을 나눈 나머지 저장
    }

    return DP[n];
}