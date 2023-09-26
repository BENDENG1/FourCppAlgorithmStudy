/*
124 -> 자연수 / 1,2,4만 사용

그냥 4를 1로 생각하고 구하면 편하네 ㅇㅇ
*/
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(int n) {
    string answer = "";
    
    while(n > 0){
        if(n % 3 == 0){
            answer += '4';
            n--;
        }else{
            answer += (n % 3) + '0' ;
        }
        n /= 3;
    }
    reverse(answer.begin(),answer.end());
    return answer;
}