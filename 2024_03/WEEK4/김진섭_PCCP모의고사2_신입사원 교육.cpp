//문제풀이: https://githubseob.tistory.com/374

#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> ability, int number) {
    int answer(0);
    priority_queue<int, vector<int>, greater<int>>pq_clerk;

    for (int idx = 0; idx < ability.size(); ++idx) {
        pq_clerk.push(ability[idx]);
    }

    for (int idx = 0; idx < number; ++idx) {
        int clerk_1 = pq_clerk.top();
        pq_clerk.pop();
        int clerk_2 = pq_clerk.top();
        pq_clerk.pop();
        pq_clerk.push(clerk_1 + clerk_2);
        pq_clerk.push(clerk_1 + clerk_2);
    }

    while (!pq_clerk.empty()) {
        answer += pq_clerk.top();
        pq_clerk.pop();
    }
    return answer;
}