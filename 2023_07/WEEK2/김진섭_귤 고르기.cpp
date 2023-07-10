//문제풀이: https://githubseob.tistory.com/281

#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer(0), idx(0), cnt(0);
    priority_queue<int>pq;

    sort(tangerine.begin(), tangerine.end());
    tangerine.push_back(-1);

    for (idx = 0; idx < tangerine.size(); ++idx) {
        ++cnt;
        if (tangerine[idx] != tangerine[idx + 1]) {
            pq.push(cnt);
            cnt = 0;
        }
    }

    while (k > 0) {
        k -= pq.top();
        pq.pop();
        answer++;
    }

    return answer;
}