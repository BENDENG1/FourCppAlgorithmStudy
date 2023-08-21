/*
프로세스

실행 대기 큐에서 대기중인 프로세스를 하나 꺼냄
우선순위가 더 높은 프로세스를 꺼내고 방금 꺼낸것을 다시 집어 넣음
*/
#include <string>
#include <vector>
#include <queue>
#include <cstring>
#include <iostream>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    
    int arr[10]; // 숫자의 갯수
    queue<pair<int,int>> q; //우선순위와 location을 queue로
    int max_num = 9; // 원소는 1이상 9이하 정수 9가 최댓값
    
    memset(arr,0,sizeof(arr));
    
    for(int i =0;i<priorities.size();i++){
        q.push(make_pair(priorities[i],i));
        arr[priorities[i]]++;
    }
    
    while(!q.empty()){
        int num = q.front().first;
        int index = q.front().second;
        
        while(arr[max_num] == 0){
            max_num--; //비어있는 숫자에 대해서 내리면서 처리
        }
        if(num >= max_num){
            arr[max_num]--;
            q.pop();
            answer++;
            if(index == location)
                return answer;
        }else{
            q.pop();
            q.push(make_pair(num,index));
        }
    }
    
    return answer;
}