//문제풀이: https://githubseob.tistory.com/184

#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer(0);
    priority_queue<int, vector<int>, greater<int>>pq;

    for (int idx = 0; idx < scoville.size(); ++idx) {
        pq.push(scoville[idx]);
    }

    while (!pq.empty()) {
        if (pq.top() >= K) break;
        int num1 = pq.top();
        pq.pop();
        if (pq.empty()) break;
        int num2 = pq.top();
        pq.pop();
        pq.push(num1 + num2 * 2);
        ++answer;
    }

    if (pq.empty()) return -1;
    return answer;
}