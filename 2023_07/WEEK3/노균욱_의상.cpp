/*
의상

일부가 겹치더라도 다른 의상이 겹치지 않거나 혹은 의상을 추가로 착용 -> 서로 다른 방법으로 계산
["의상 이름", "의상 종류"]로 주어진다.
의상 종류가 n개라면 1개의 조합일때~ n개의 조합일때를 생각.

의상 1~n종류일때 i개의 조합을 따진다고 생각을 하면 
i개의 조합이 
예를 들어 3개를 하는데 종류는 4개 의상의 갯수가 a,b,c,d라면
a*b*c + a*b*d + b*c*d 가 되는 것이다.
즉, 겹치지 않는 모든 곱셈의 합을 구해야 합니다.
*/

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    vector<pair<string,int>> v;
    
    v.push_back(make_pair(clothes[0][1],1));
    
    for(int i = 1 ;i < clothes.size();i++){
        int flag = 0; // 플래그로 v에 존재 하지 않으면 push_back
        for(int j = 0; j < v.size();j++){
            if(v[j].first == clothes[i][1]){
                v[j].second++;
                flag = 1;
                break;
            }
        }
        if(flag == 0){
            v.push_back(make_pair(clothes[i][1],1));
        }
        
    }

    //여기서 1 2 3 4 라면
    // 1 + 2 + 3 + 4 + 1*2 + 1*3 + 1*4 + 2*3 + 3*4 + .... + 1*2*3*4가 되어야함
    // 이것은 (1+1) * (2+1) * (3+1) * (4+1) -1과 같습니다.
    for(int i = 0; i < v.size();i++){
        answer *= (v[i].second + 1);
    }
    return answer - 1;
}