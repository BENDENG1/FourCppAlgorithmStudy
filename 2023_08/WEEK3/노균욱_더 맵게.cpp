/*
스코빌 지수를 k이상 만듬

가장 맵지 x + (두번째 맵지x *2) -> k이상까지

k는 10억 이하 -> int가능
k이상 만들수 없을때 -1리턴

*/
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    int sum = 0;
    priority_queue<int,vector<int>, greater<int>> pq;
    
    for(int i = 0; i < scoville.size();i++){
        pq.push(scoville[i]);
    }
    
    while(1){
        if(pq.top() >= K)
            break;
        if(pq.size() <= 1 && pq.top() < K)
            return -1;
        sum = pq.top();
        pq.pop();
        sum += 2 * pq.top();
        pq.pop();
        pq.push(sum);
        answer++;
    }
    
    return answer;
}