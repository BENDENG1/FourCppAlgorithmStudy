//문제풀이: https://githubseob.tistory.com/375

#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> menu, vector<int> order, int k) {
    int answer(1);
    int time(0), count(0);
    queue<int>waiting;

    for (int idx = 0; idx < order.size(); ++idx) {
        while (!waiting.empty() && waiting.front() <= idx * k) {
            waiting.pop();
        }
        if (time > k * idx) {
            time += menu[order[idx]];
        }
        else time = k * idx + menu[order[idx]];
        waiting.push(time);
        count = waiting.size();
        answer = max(answer, count);

    }

    return answer;
}