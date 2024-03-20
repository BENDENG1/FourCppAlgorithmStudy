//문제풀이: https://githubseob.tistory.com/372

#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#define pii pair<int, int>
using namespace std;

struct cmp1 {
    bool operator()(pii& p1, pii& p2) {
        if (p1.first == p2.first) return p1.second > p2.second;
        return p1.first > p2.first;
    }
};

bool cmp2(vector<int>& v1, vector<int>& v2) {
    return v1[1] < v2[1];
}

vector<long long> solution(vector<vector<int>> program) {
    vector<long long> answer(11, 0);
    priority_queue<pii, vector<pii>, cmp1>pq;
    sort(program.begin(), program.end(), cmp2);

    int program_idx(0), idx(0), time(0);

    while (idx < program.size()) {
        while (idx < program.size() && (pq.empty() || time >= program[idx][1])) {
            if (pq.empty() && time < program[idx][1]) {
                time = program[idx][1];
            }
            pq.push({ program[idx][0] , idx });
            ++idx;
        }

        program_idx = pq.top().second;
        pq.pop();

        answer[program[program_idx][0]] += time - program[program_idx][1];
        time += program[program_idx][2];
    }

    while (!pq.empty()) {
        program_idx = pq.top().second;
        pq.pop();

        answer[program[program_idx][0]] += time - program[program_idx][1];
        time += program[program_idx][2];
    }

    answer[0] = time;
    return answer;
}