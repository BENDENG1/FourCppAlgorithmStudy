//문제풀이: https://githubseob.tistory.com/327

#include <string>
#include <vector>
#define INF 1e6
using namespace std;


int solution(int x, int y, int n) {
    vector<int>DP(y + 1, INF);

    DP[x] = 0;
    for (x; x <= y; ++x) {
        if (x + n <= y && DP[x + n] > DP[x] + 1)
            DP[x + n] = DP[x] + 1;

        if (x * 2 <= y && DP[x * 2] > DP[x] + 1)
            DP[x * 2] = DP[x] + 1;

        if (x * 3 <= y && DP[x * 3] > DP[x] + 1)
            DP[x * 3] = DP[x] + 1;

        if (DP[y] != INF) return DP[y];
    }

    return -1;
}