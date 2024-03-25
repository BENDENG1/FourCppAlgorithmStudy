#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>
using namespace std;

int solution(vector<int> ability, int number) {
    long long answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(auto a : ability){
        pq.push(a);
    }
    for(int i=0; i<number; i++){
        int temp1 = pq.top();
        pq.pop();
        int temp2 = pq.top();
        pq.pop();
        pq.push(temp1 + temp2);
        pq.push(temp1 + temp2);
    }
    while(!pq.empty()){
        answer += pq.top();
        pq.pop();
    }
    return answer;
}

