//문제풀이: https://githubseob.tistory.com/356

#include <string>
#include <vector>
#include <stack>
using namespace std;

bool isCorrect(string s) {
    stack<char>stk;
    for (int idx = 0; idx < s.size(); ++idx) {
        if (s[idx] == '(') stk.push('(');
        else if (s[idx] == ')') {
            if (stk.empty()) return false;
            else if (stk.top() == '(') stk.pop();
        }
    }
    return true;
}

string convert(string w) {
    if (w.empty()) return w;

    string ret(""), u(""), v("");
    int open(0), close(0), idx(0);

    for (idx = 0; idx < w.size(); ++idx) {
        if (w[idx] == '(') ++open;
        else if (w[idx] == ')') ++close;

        u += w[idx];
        if (open == close) {
            break;
        }
    }
    v = w.substr(idx + 1);

    if (isCorrect(u) == true) ret = u + convert(v);
    else {
        ret = "(" + convert(v) + ")";

        for (int idx = 1; idx + 1 < u.size(); ++idx) {
            if (u[idx] == '(') ret += ")";
            else if (u[idx] == ')') ret += "(";
        }
    }
    return ret;
}

string solution(string p) {
    return convert(p);
}