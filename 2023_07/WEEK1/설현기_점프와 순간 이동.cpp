/* 주어진 숫자를 0이 될때까지 2로 나누며 나누면서(시간 역행?) n이 홀수인 경우가 목표지점을 가기위해
 최소한의 점프를 한 횟수로 생각하고 홀수일 경우일때마다 ans++를 해주고 -1을 해주는 동작을 반복*/ 
#include <iostream>
using namespace std;

int solution(int n)
{
    int ans = 0;
    while(n > 0){ 
        if(n % 2 == 1){
            ans++;
            n -= 1;
        }
        n /= 2;
    }
    
    return ans;
}