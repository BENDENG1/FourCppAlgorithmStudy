/*
일단은 만약 전체가 1또는 0이라면 하나로 끝이 난다.

이것에 대해서 0,0 -> n,n에 대해서 측정을하고 아니라면 쪼개는 TopDown방식을 하는 것이 나은듯?

dfs를 topdown으로 계속 반으로 쪼개주면서 1,2,3,4분면으로 쪼개면서 검사를 하면됨
*/
#include <string>
#include <vector>

using namespace std;

vector<int> answer(2,0);

void dfs(int y, int x, int size, vector<vector<int>> &arr){
    int oneCnt = 0;
    int zeroCnt = 0;
    
    for(int i = y; i < y + size; i++){
        for(int j = x; j < x + size; j++){
            if(arr[i][j] == 0)
                zeroCnt++;
            else
                oneCnt++;
            if(oneCnt != 0 && zeroCnt != 0)
                break;
        }
    }
    if(zeroCnt ==0 && oneCnt == 0)
        return;
    else if(zeroCnt == 0){
        answer[1]++;
        return;
    }else if(oneCnt == 0) {
        answer[0]++;
        return;
    }
    dfs(y,x,size/2,arr);
    dfs(y+size/2,x,size/2,arr);
    dfs(y,x+size/2,size/2,arr);
    dfs(y+size/2,x+size/2,size/2,arr);
}

vector<int> solution(vector<vector<int>> arr) {
    dfs(0,0,arr.size(),arr);
    return answer;
}