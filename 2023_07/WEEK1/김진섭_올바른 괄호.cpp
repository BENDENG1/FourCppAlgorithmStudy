//문제풀이: https://githubseob.tistory.com/239

#include <string>
#include <iostream>
#include <stack>
using namespace std;

bool solution(string s)
{
    bool answer(true);
    stack<char>st;
    int idx(0);
    for (idx = 0; idx < s.size(); ++idx) {
        if (st.empty() && s[idx] == ')') {
            return false;
        }
        else if (s[idx] == '(') {
            st.push('(');
        }
        else if (s[idx] == ')') {
            st.pop();
        }
    }
    if (st.empty())
        return true;
    else return false;
}