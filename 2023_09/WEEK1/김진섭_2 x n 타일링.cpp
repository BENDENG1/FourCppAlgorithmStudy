//문제풀이: https://githubseob.tistory.com/328

#include <string>
#include <vector>
#define MOD 1000000007
using namespace std;

int solution(int n) {
    vector<int>DP(n + 1, 0);

    DP[0] = 1;
    DP[1] = 1;

    for (int idx = 2; idx <= n; ++idx)
        DP[idx] = (DP[idx - 2] + DP[idx - 1]) % MOD;

    return DP[n];
}