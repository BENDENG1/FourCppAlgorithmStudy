/*
행렬의 곱 
(행 * 열) * (행 * 열) = 행 * 열 
가로로 첫번째 행렬의 열들과 두번째 행렬의 행이 곱해진다는 것을 알아야 함.
ex)
1 2    5 6
3 4    7 8
의 두행렬의 곱셈은
1*5+2*7 1*6+2*8
3*5+4*7 3*6+4*8 이 된다.

사실 행렬의 곱셈 자체를 공식을 알게 된다면 편하다. 물론 몰라도 입출력 예시 2번째를 보게 되면 알 수 있다.
5 2 2 5

*/
#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    
    vector<int> col;
    
    int sum =0;
    
    for(int i = 0; i < arr1.size();i++){
        col.clear();
        for(int j = 0; j < arr2[0].size(); j++){
            sum = 0;
            for(int k = 0;k< arr1[0].size(); k++){
                sum += arr1[i][k] * arr2[k][j];
            }
            // cout<<sum <<" ";
            col.push_back(sum);
        }
        answer.push_back(col);
    }
    return answer;
}