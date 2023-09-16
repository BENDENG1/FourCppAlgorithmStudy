/*
반시계방향으로 돌면서 채움 순서대로 숫자를 채운후 리턴을 하는 것.

방식에 대해서 고민을 해봐야하는 문제 인것 같은데

1열 -> 1개,2열 2개 ,3열 3개

우선 최하단으로 아래로 보낸다(하단에 visited가 false일때)
-> 최하단이라면 오른쪽으로 보낸다(범위의 맨 아래 혹은 아래가 visited가 false일때)
-> 맨 오른쪽이면 -1,-1좌표값으로 이동한다.()

1
2 12
3 13 11
4 14 15 10
5 6  7  8  9 이런식으로 보면 위의 사항을 이해하기 편할듯 싶어 적어좀
*/
#include <string>
#include <vector>

using namespace std;

int maxNum = 0;
void dfs(int y,int x,int num,vector<vector<int>> &v);

vector<int> solution(int n) {
    vector<int> answer;
    vector<vector<int>> v;
    
    for(int i = 1 ; i <= n;i++){
        vector<int> rowVector(i,0);
        v.push_back(rowVector);
        maxNum += i;
    }
    dfs(0,0,1,v);
    for(int i = 0 ; i < v.size();i++){
        for(int j = 0 ; j < v[i].size();j++){
            answer.push_back(v[i][j]);
        }
    }
    
    return answer;
}

void dfs(int y,int x,int num,vector<vector<int>> &v){
    v[y][x] = num;
    while(num < maxNum){
        while(y+1 < v.size() && !v[y+1][x]){
            v[++y][x] = ++num;
        }
        while(x+1 < v[y].size() && !v[y][x+1]){
            v[y][++x] = ++num;
        }
        while(0 <= y-1 && 0 <= x-1 && !v[y-1][x-1]){
            v[--y][--x] = ++num;
        }
    }
}