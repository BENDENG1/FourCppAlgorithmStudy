/*
두 개의 큐 pop insert를 하여 합이 같도록 진행
pop + insert -> 1회 수행

원소의 합을 일단 추출
*/
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    int size = queue1.size() + queue2.size();
    long oneSum = 0;
    long twoSum = 0;
    int tmp = 0;    
    queue<int> q1;
    queue<int> q2;
    
    for(int i = 0; i < queue1.size();i++){
        oneSum += queue1[i];
        q1.push(queue1[i]);
    }
    for(int i = 0; i < queue2.size();i++){
        twoSum += queue2[i];
        q2.push(queue2[i]);
    }
    
    
    while(answer <= size + 2){
        if(oneSum == twoSum) return answer;
        if(oneSum > twoSum){
            tmp = q1.front();
            q1.pop();
            oneSum -= tmp;
            twoSum += tmp;
            q2.push(tmp);
            answer++;
        }else if(oneSum < twoSum){
            tmp = q2.front();
            q2.pop();
            oneSum += tmp;
            twoSum -= tmp;
            q1.push(tmp);
            answer++;
        }
    }
    
    return -1;
}