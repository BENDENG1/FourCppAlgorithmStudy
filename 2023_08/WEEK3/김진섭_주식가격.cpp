//문제풀이: https://githubseob.tistory.com/141

#include <string>
#include <vector>
#include <stack>
#define pii pair<int, int>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size());
    stack<pii> stk;

    stk.push({ prices[0], 0 });
    for (int idx = 1; idx < prices.size(); ++idx) {
        while (!stk.empty() && stk.top().first > prices[idx]) {
            answer[stk.top().second] = idx - stk.top().second;
            stk.pop();
        }
        stk.push({ prices[idx], idx });
    }
    while (!stk.empty()) {
        answer[stk.top().second] = prices.size() - 1 - stk.top().second;
        stk.pop();
    }

    return answer;
}