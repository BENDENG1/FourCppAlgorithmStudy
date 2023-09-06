#include <string>
#include <vector>

#define MOD 1000000007
using namespace std;

int solution(int n) {
    int pibo[60001] = {0};
    pibo[1] = 1;
    pibo[2] = 2;
    int answer = 0;

    for(int i = 3; i <= n; i++)
    {
        pibo[i] = (pibo[i - 1] + pibo[i - 2]) % MOD;
    }
    answer = pibo[n];
    return answer % MOD;
}