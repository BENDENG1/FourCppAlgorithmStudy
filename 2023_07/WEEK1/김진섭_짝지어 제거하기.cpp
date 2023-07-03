//문제풀이: https://githubseob.tistory.com/253

#include <string>
#include <stack>
using namespace std;

int solution(string s) { // 올바른 괄호 응용
    int idx(0);
    stack<char>alp;

    for (idx = 0; idx < s.size(); ++idx) {
        if (!alp.empty() && alp.top() == s[idx]) { 
            alp.pop();
            // 비어있지 않고 맨앞이 같은 단어이면 pop;
        }
        else {
            alp.push(s[idx]); //다르면 push
        }
    }

    return alp.empty(); //굳
}