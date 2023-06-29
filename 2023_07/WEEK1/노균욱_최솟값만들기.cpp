/*
생각해보면 정말 어처구니 없었다. 사실 자연수이기 때문에 브루트포스가 필요가 없는데
또 자연수가 아니더라도 분류를 거기서 처리를 하면 되는데
굳이 모든 조합을 계산하다고 백트레킹 + 브루트포스로 구현한 삽푼 문제다.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;
    int len = A.size();
    vector<int> a_v = A;
    vector<int> b_v = B;
    sort(a_v.begin(),a_v.end());
    sort(b_v.begin(),b_v.end());
    
    for(int i = 0; i < len;i++){
        answer += (a_v[i] * b_v[len - i - 1]);
    }
    return answer;
}