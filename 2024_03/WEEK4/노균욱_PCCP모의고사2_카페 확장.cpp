/*
카페 확장 

k초마다 손님 줄 + 1 / 받은순서대로 만듬 / 같은 종류 음료 시간 항상 동일
최대 몇명이 머물렀는지 / 만드는 시간만 고려

동시에 존재한 시간을 찾는 문제 -> 그냥 현재시간 + 큐를 전언해서 고려하면 되는거아닌가?
*/

#include <string>
#include <vector>
#include <queue>

#define NEGATIVE -100

using namespace std;



int solution(vector<int> menu, vector<int> order, int k) {
    int answer = 0;
    queue<int > q;
    int totalTime = k * (order.size() - 1);
    int makeTime = NEGATIVE;
    int cur = 0, turn = 0;
    
    while(cur <= totalTime){
        if(cur == makeTime){
            q.pop();
            makeTime = NEGATIVE;
        }
        if(cur == k * turn)
            q.push(order[turn++]);
        if(makeTime == NEGATIVE && !q.empty()){
            makeTime = cur + menu[q.front()];
        }
        answer = answer > q.size() ? answer : q.size();
        cur++;
    }
    return answer;
}


/*

int solution(vector<int> menu, vector<int> order, int k) {
    int answer = 0;
    queue<int> q;
    
    int curTime = 0;
    int makeTime = menu[order[0]];
    int sumTime = 0;
    int turn = 0;
    
    while(1){
        if(!q.empty()){
            if(makeTime < curTime)
                makeTime += q.front();
            else if(makeTime == curTime)
                q.pop();   
        }
        
        if(turn * k == curTime){
            q.push(menu[order[turn]]);
            turn++;
        }
        curTime++;
        
        answer = answer > q.size() ? answer : q.size();
        if(turn == order.size())
            break;
    }
    
    return answer;
}
*/