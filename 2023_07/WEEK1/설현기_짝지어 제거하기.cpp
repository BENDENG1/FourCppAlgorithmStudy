#include <iostream>
#include<string>
#include<stack>
using namespace std;

int solution(string s)
{
    int answer = -1;
    stack<char> st;
    
    for(char c : s){
        if(!st.empty() && c == st.top()){
            st.pop();
        }
        else{
            st.push(c);
        }
    }
    
    return st.empty();
}