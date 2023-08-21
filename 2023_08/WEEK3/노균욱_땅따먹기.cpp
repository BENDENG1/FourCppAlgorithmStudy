/*
땅따먹기

n행 4열
같은 열을 연속해서 밟을 수 없는 특수 규칙
첫번재꺼에 대해서 저장하고 다음 부터는 1이라면 1을 제외한 234에서 최댓값을 추가하는 식이 좋을듯.
*/
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> land)
{
    int answer = 0;
    int arr[4] ={0,};
    
    if(land.size() == 1){
        return *max_element(land[0].begin(),land[0].end());
    }
    
    for(int i = 1; i < land.size();i++){
        for(int j = 0; j < 4; j++){
            int score_max = 0; //가장 높은 스코어를 올릴 수 있는 상황
            for(int k = 0; k < 4;k++){
                if(k != j){
                    if(score_max < land[i-1][k])
                        score_max = land[i-1][k];
                }
            }
            land[i][j] += score_max;
        }
    }
    
    for(int i = 0; i < 4; i++){
        if(answer < land[land.size() - 1][i])
            answer = land[land.size() - 1][i];
    }
    

    return answer;
}