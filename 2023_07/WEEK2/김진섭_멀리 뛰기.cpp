//문제풀이: https://githubseob.tistory.com/280
#include <string>
#include <vector>
#define DIV 1234567
using namespace std;

long long solution(int n) {
    int idx(0);
    vector<long long>DP(n + 1, 0);

    DP[0] = 1;
    DP[1] = 1;    
    for (idx = 2; idx <= n; ++idx) {
        DP[idx] = (DP[idx - 1] + DP[idx - 2]) % DIV;
    }

    return DP[n];
}