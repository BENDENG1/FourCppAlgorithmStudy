/*
n의 다음 큰 숫자는 n보다 큰 자연수
n의 다음 큰 숫자와 n은 2진수 변환시 1의 갯수 같음
n의 다음 큰 숫자는 조건 1,2를 만족중 가장 작은 수.

이렇게 보면 
1) 일단 n을 2진수로 변환한다
2) 1111111 이런식이 아니라면 가장 우측의 두번째를 한칸 올리고 맨끝은 맨 뒤로
2 - 1 만약 두번째왼쪽에 3번째가 바로 있으면 세번째를 밀고 두개를 다 맨 우측으로 이런식ㅇㅇ
2 - 2 1111111 이런 식이면 10을 만들고 남은갯수 1다 추가 1111 -> 10111
ex) 
n : 10101100
한칸 올리고 우측 -> 10110001

생각해보니 이렇게 복잡하게 하는것보다 그냥 79부터 카운팅을 해서 다음 비트를 뽑는게 제일 나을지도? -> 채택
*/
#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int one_cnt = 0;
    int comp_num  = n;
    
    while(n > 0){
        if(n%2 == 1)
            one_cnt++;
        n /= 2;
    }
    n = comp_num; // n을 다시 돌려놔야함
    
    while(1){
        n++;
        int comp_cnt = 0;
        comp_num = n;
        while(comp_num > 0){
            if(comp_num%2 == 1)
                comp_cnt++;
            comp_num /= 2;
        }
        if(comp_cnt == one_cnt)
            break;
    }
    answer = n;
    return answer;
}