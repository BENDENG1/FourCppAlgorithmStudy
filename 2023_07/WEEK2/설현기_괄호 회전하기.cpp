/* 계속 괄호를 회전하면서 체크하기 위해 2중for문 사용, 스택과 boolean 변수 flag를 false로 초기화하여 생성하고
현재 괄호를 첫 괄호부터 탐색하는데 열린 괄호면 flag를 true로 설정, 스택에 push하고, 
현재 괄호가 닫힌 괄호인데 스택의 top이 짝이 맞는 열린괄호면 pop을 한다.
탐색 후에 스택이 비어있고, flag가 true라면 올바른 괄호 문자열이기 때문에 answer에 +1해주고
첫 괄호를 맨 뒤에 삽입하고 첫 괄호를 삭제하여 회전한 모습을 만들어준다.*/
#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(string s) {
    int answer = 0;

    for (int i = 0; i < s.size(); i++) {
        stack<char> st;
        bool flag = false;
        for (int j = 0; j < s.size(); j++) {
            if (s[j] == '[' || s[j] == '{' || s[j] == '(') {
                flag = true;
                st.push(s[j]);
            }
            else {
                if (s[j] == ']' && st.top() == '[')
                    st.pop();
                if (s[j] == '}' && st.top() == '{')
                    st.pop();
                if (s[j] == ')' && st.top() == '(')
                    st.pop();
            }
        }
        if (st.empty() && flag) answer++;

        char ch = s.front();
        s.erase(s.begin());
        s.push_back(ch);
    }
    return answer;
}