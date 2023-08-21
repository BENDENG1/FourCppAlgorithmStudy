/*
N개의 최소 공배수

일단 소수라면? -> 그냥 곱하면 되지 않을까? 근데 소수 , 소수 *n을 비교할 수도 있음
그럼 2이상의 숫자에서 같이 나눠지는것은 다 나누는 행위?

100이하니 100까지 가면서 혹은 2부터 max인 친구까지 가면서 그 숫자까지 일단 나눠지는 것이 두개 이상이 있다면 나눔

*/
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> arr) {
    int answer = 1;
    int div_arr[15];
    
    int max_num = *max_element(arr.begin(),arr.end());
    int i = 2;
    while(i <= max_num){
        int div_cnt = 0; // cnt -> 나눠지게 되면 cnt++을 진행해 2개 이상 체크
        memset(div_arr,0,sizeof(div_arr));
        for(int j = 0;j < arr.size();j++){
            if(arr[j] % i == 0){
                div_cnt++;
                div_arr[j] = 1;
            } 
        }
        if(div_cnt >= 2){
            for(int j =0; j < arr.size();j++){
                if(div_arr[j] == 1)
                    arr[j] /= i;
            }
            answer *= i;
            i = 1;
            max_num = *max_element(arr.begin(),arr.end());
        }
        i++;
    }
    
    for(int i = 0; i < arr.size(); i++){
        answer *= arr[i];
    }
    
    return answer;
}