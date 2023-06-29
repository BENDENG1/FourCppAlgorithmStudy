/*
연속된 숫자의 합이니깐 반복문을 돌때 j가 i일때부터 n을 넘기기 전까지 넘긴다면 애초에 말이 안되는거니깐
근데 만약에 j = n이면 이탈하는거로 결정

그리고 숫자의 반 + 1까지만 돌아도 됨
ex)
10000 -> 5000 + 5001을 하면 애초에 이탈임
9999 -> 4999 + 5000하면 딱 맞음 
*/
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 0;
    for(int i = 1; i < (n/2) + 1; i++){
        int j = i;
        int sum = 0;
        while(j<n){
            sum += j;
            if(sum == n){ //숫자가 맞으면 진행
                cout<<j;
                answer++;
                break;
            }else if(sum > n)
                break;
            j++;
        }
    }
    answer++; //만약 10000이라면 5000까지 돌았으니 10000은 되는거니깐 
    return answer;
}