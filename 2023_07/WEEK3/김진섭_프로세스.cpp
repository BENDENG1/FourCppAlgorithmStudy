//문제풀이: https://githubseob.tistory.com/305

#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer(0), idx(0), num(0);
    priority_queue<int>pq;
    queue<pair<int, int>>q;
    for (idx = 0; idx < priorities.size(); ++idx) {
        q.push({ priorities[idx],idx });
        pq.push(priorities[idx]);
    }

    while (!pq.empty()) {
        num = q.front().first;
        idx = q.front().second;
        q.pop();
        if (num == pq.top()) {
            ++answer;
            if (idx == location) return answer;
            pq.pop();
        }
        else {
            q.push({ num, idx });
        }
    }

    return answer;
}