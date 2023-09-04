#include <string>
#include <vector>
#define max 1000000
using namespace std;

int solution(int x, int y, int n) {
    int answer = 0;
    vector<int> DP(y+1,max);
    DP[x]=0;
        for (int i = x; i <= y; i++) {
        if (i * 3 <= y) {
            DP[i * 3] = min(DP[i * 3], DP[i] + 1);
        }
        if (i * 2 <= y) {
            DP[i * 2] = min(DP[i * 2], DP[i] + 1);
        }
        if (i + n <= y) {
            DP[i + n] = min(DP[i + n], DP[i] + 1);
        }
    }
    return DP[y] == max ? -1 : DP[y];
}