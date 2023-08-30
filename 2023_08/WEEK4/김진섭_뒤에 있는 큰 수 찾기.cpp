//문제풀이: https://githubseob.tistory.com/317

#include <string>
#include <vector>
#include <stack>
#define pii pair<int, int>
using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer(numbers.size(), -1);
    stack<pii>stk;
    for (int idx = 0; idx < numbers.size(); ++idx) {
        while (!stk.empty() && stk.top().first < numbers[idx]) {
            int num_idx = stk.top().second;
            answer[num_idx] = numbers[idx];
            stk.pop();
        }
        stk.push({ numbers[idx], idx });
    }

    return answer;
}