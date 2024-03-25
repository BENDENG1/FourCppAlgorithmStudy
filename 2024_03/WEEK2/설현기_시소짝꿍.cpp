#include <string>
#include <vector>

using namespace std;

long long solution(vector<int> weights) {
    long long answer = 0;
    vector<long long> cnt(1001, 0);
    
    for(int i = 0; i < weights.size(); i++)
        cnt[weights[i]]++;
    
    for(int i = 0; i < weights.size(); i++) {
        // 2:3
        if(weights[i] % 2 == 0) {
            long long base  = (weights[i] / 2) * 3;
            if(base <= 1000)    answer += cnt[base];
        }
        // 3:4
        if(weights[i] % 3 == 0) {
            long long base  = (weights[i] / 3) * 4;
            if(base <= 1000)    answer += cnt[base];
        }
        // 2:4
        long long base  = weights[i] * 2;
        if(base <= 1000)    answer += cnt[base];
    }

    // 몸무게 같은 경우 처리
    for(int i = 100; i <= 1000; i++) {
        if(cnt[i] >= 2)
            answer += (long long)(cnt[i] * (cnt[i] - 1)) / 2; // n개 중에 2개 뽑는 경우의 수 : n(n-1) / 2
    }
    
    return answer;
}