/*
토너먼트 방식으로 진행 A,B 언제 만나는지 return
단,a와b는 항상 이겨서 무조건 올라와서 만난다는 가정
8 4 7 -> 3
16 4 7 -> 3
16 4 15 -> 4

중간을 나눴는데 그를 기준으로 나눠진다면 log2 n 이 되는거임
결국 2를 계속 나누면서 나눠지면 최댓값 아닐까?
부전승 없음
*/

#include <iostream>
#include <cmath>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;
    int two_pow = n;
    
    //a가 b보다 작게 설정을 하고 싶어서(조건문 귀찮음) 크다면 스왑
    if(a > b){
        int tmp = b;
        b = a;
        a = tmp;
    }
    while (two_pow > 1){
        answer ++;
        two_pow /= 2;
    }
    
    while (n > 0){
        n /= 2;
        if(a <= n && b <= n){
            answer--;
        }else if(a <= n && n < b){
            return answer;
        }else{
            a -= n;
            b -= n;
            answer--;
        }
    }
    return answer;
}