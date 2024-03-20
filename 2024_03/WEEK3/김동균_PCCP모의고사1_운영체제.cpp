#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void callPrograms(vector<vector<int>>& program, int cur, priority_queue<vector<int>, vector<vector<int>>, greater<>>& q) {
    while (!program.empty() && program[0][1] <= cur) {
        q.push(program[0]);
        program.erase(program.begin());
    }
}
//현재 시간을 기준으로 
bool compare(const vector<int>& p1, const vector<int>& p2) {
    return p1[1] < p2[1];
}
vector<long long> solution(vector<vector<int>> program) {
    vector<long long> answer(10, 0);
    priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
    int Time = 0;

    sort(program.begin(), program.end(), compare);

    while (!program.empty() || !pq.empty()) {
        if (pq.empty()) {
            Time = program[0][1];
        }
        else {
            vector<int> ExVector = pq.top();
            pq.pop();
            answer[ExVector[0] - 1] += Time - ExVector[1];
            Time += ExVector[2];
        }

        callPrograms(program, Time, pq);
    }

    answer.insert(answer.begin(), Time);
    return answer;
}