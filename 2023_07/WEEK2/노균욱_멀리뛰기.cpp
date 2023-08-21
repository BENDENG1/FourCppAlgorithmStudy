/*
멀리뛰기 연습

1칸 또는 2칸을 뛸 수 있다는 것의 조합 -> 무조건 dp문제인듯 하다

사유 : dp로 인해 그 전에 dp[i] = dp[i-1] + dp[i -2] 이기 때문이다.
    그리고 n은 2000이하라는 제한사항을 보게 되면 역시 그럼을 다시 알 수 있다.

주의 사항 : 1234567을 나눈 나머지를 리턴한다는 점. 
*/

#include <string>
#include <vector>

using namespace std;

long long solution(int n) {
    long long answer = 0;
    
    if(n == 1)
        return 1;
    else if(n == 2)
        return 2;
    
    vector<int> v(n,0); //백터의 n크기를 0으로 일단 셋팅
    v[0] = 1,v[1] = 2; //dp는 초기를 셋팅후 진행
    
    for(int i =2; i < n; i ++){
        v[i] = (v[i-1] + v[i - 2]) % 1234567;
    }
    
    answer = v.back();
    
    
    return answer;
}
