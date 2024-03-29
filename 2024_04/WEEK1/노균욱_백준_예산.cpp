/*
예산

1. 모든 요청 가능 -> 다 배정
2. 정수 상한액 설정

일단 초과하는지 체크 / 아니라면 그냥 최댓값 출력

*/
#include <iostream>

using namespace std;

int arr[100001] = {0,};

int main(){
    int n, tmp, budget, sum = 0;

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> tmp;
        sum += tmp;
        arr[tmp]++;
    }

    cin >> budget;


}