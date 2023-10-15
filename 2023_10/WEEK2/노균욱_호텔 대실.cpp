/*
최소 객실의 수 

*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<string>> bt) {
    int answer = 0;
    int time[1440] = {0,};
    
    for(int i = 0 ; i < bt.size();i++){
        int start = stoi(bt[i][0].substr(0,2))*60 + stoi(bt[i][0].substr(3));
        int end = stoi(bt[i][1].substr(0,2)) * 60 + stoi(bt[i][1].substr(3)) + 10;
        for(int j = start; j<end; j++){
            time[j]++;
        }
    }
    
    for(int i = 0 ; i < 1440;i++){
        answer = max(answer,time[i]);
    }
    
    return answer;
}