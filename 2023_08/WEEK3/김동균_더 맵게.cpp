#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> q; // Min-heap을 위해 greater를 사용

    // 우선순위 큐에 scoville을 모두 넣어줌
    for (int s : scoville) {
        q.push(s);
    }

    while (q.size() >= 2 && q.top() < K) {
        int least_spicy = q.top();
        q.pop();
        int second_least_spicy = q.top();
        q.pop();

        int new_spicy = least_spicy + (second_least_spicy * 2);
        q.push(new_spicy);

        answer++;
    }

    if (q.top() < K)
        answer = -1;

    return answer;
}