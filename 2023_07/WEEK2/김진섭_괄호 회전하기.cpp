//문제풀이: https://githubseob.tistory.com/193

#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(string s) {
    int answer(0), idx(0), idx2(0);
    s += s;
    stack<char>bracket;
    for (idx = 0; idx < s.size() / 2; ++idx) {
        bracket = stack<char>();
        for (idx2 = idx; idx2 < s.size() / 2 + idx; ++idx2) {
            if (s[idx2] == '(' || s[idx2] == '{' || s[idx2] == '[') {
                bracket.push(s[idx2]);
            }
            else if (!bracket.empty()) {
                if (bracket.top() == '(' && s[idx2] == ')') {
                    bracket.pop();
                }
                else if (bracket.top() + 2 == s[idx2]) {
                    bracket.pop();
                }
            }
            else {
                break;
            }

        }
        if (idx2 == s.size() / 2 + idx && bracket.empty()) {
            answer++;
        }
    }
    return answer;
}