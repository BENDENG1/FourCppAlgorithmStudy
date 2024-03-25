/*
신입사원 교육

서로의 능력 흡수 -> 두 능력이 합이 됨 3,7 -> 10,10

신입사원들의 능력치 합이 최소가 되게 하고 싶음

그냥 최소들끼리 합하고 갱신하고 거시서 가장 최소들끼리 합하고 반복아닌가
*/
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> ability, int number) {
    int answer = 0;
    
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for(auto a : ability)
        pq.push(a);
    
    for(int i = 0; i < number;i++){
        int lowOne = pq.top();
        pq.pop();
        int lowTwo = pq.top();
        pq.pop();
        pq.push(lowOne + lowTwo);
        pq.push(lowOne + lowTwo);
    }
    
    while(!pq.empty()){
        answer += pq.top();
        pq.pop();
    }
    
    return answer;
}