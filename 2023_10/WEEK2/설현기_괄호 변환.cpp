#include <string>
#include <stack>

using namespace std;

bool check(string p) {
    stack<char> st;
    
    for(auto c: p) {
        if(c == '(') st.push(c);
        else {
            if(st.empty()) return false;
            st.pop();
        }
    }
    
    return st.empty();    
}

string solution(string p) {
    if(p.empty()) return p; 
    string answer = "";
    
    string u = "", v = "";
    int l = 0, r = 0;
    
    for(int i = 0; i < p.length(); ++i) {
        if(p[i] == '(') l++;
        else r++;
        
        if(l == r) {
            u = p.substr(0, i+1);
            v = p.substr(i+1);
            break;
        }
    }
    
    if(check(u)) answer = u + solution(v); 
    else { 
        answer = "(" + solution(v) + ")"; 
        
        for(int i = 1; i < u.length()-1; ++i) {
            if(u[i] == '(')
                answer += ')';
            else
                answer += '(';
        }
    }
    
    return answer;
}