#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;
    sort(A.begin(),A.end());
    sort(B.begin(),B.end(),greater<int>());
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    int result;
    while(!A.empty()){
      answer += A.back()*B.back();
      A.pop_back();
      B.pop_back();
    }
    

    return answer;
}