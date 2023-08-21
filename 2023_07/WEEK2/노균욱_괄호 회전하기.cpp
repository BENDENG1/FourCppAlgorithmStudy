/*
잘못된 생각 그냥 stack으로 할껄 그랬다. 

왜냐하면 [({)}] 이러한 형태로 ({)} 이렇게 되면 올바르지 않은 괄호이기디 때문에 스택으로 해서
스택을 푸시하는데 스택의 top과 지금 문자와 비교를 통해 진행을 하면 간단한데 괜히 시간 낭비했음
*/

#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(string s) {
    int answer = 0;
    int large = 0; //괄호들 카운팅
    int middle = 0; 
    int small = 0;
    
    //우선적으로 짝이 맞지 않는 괄호들은 계산이 필요없음 그냥 0임
    for(int i = 0; i < s.length();i++){
        if(s[i] == '(')
            small++;
        else if(s[i] == '[')
            middle++;
        else if(s[i] == '{')
            large++;
        else if (s[i] == ')')
            small--;
        else if (s[i] == ']')
            middle--;
        else if (s[i] == '}')
            large--;
    }
    if(small != 0 || middle != 0 || large != 0)
        return 0;
    
    for (int j = 0 ; j <s.length(); j++){
        stack<char>stk;
        
        for(int i =0; i < s.length();i++){
            if(s[i] == '(' || s[i] == '{' || s[i] =='[')
                stk.push(s[i]);
            else{
                if(s[i] == ')' && stk.top() == '(')
                    stk.pop();
                else if(s[i] == '}' && stk.top() == '{')
                    stk.pop();
                else if(s[i] == ']' && stk.top() == '[')
                    stk.pop();
            }
        }
        if(stk.empty())
            answer++;
        s.push_back(s[0]);
        s.erase(0,1);
    }
    return answer;
}