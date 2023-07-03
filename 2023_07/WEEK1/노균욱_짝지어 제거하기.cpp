/*
다 맞는데 효율성 모두 시간초과?
해결 과정 적어놓자
abccba라면 원래 코드의 형태라면 생각을 해보니 abc 후에 c가 들어올때 cc 이탈 bb이탈 aa이탈 하면 바로 끝내는 식으로 하면 어떨까?
스택을 사용하면 될듯?

비어있으면 비교할 대상이 없으니 일단 stack에 넣고 비어있지 않으면 비교 비교했는데 다르면 push
stack의 top과 비교해서 같으면 pop을 하면서 나중에 stack이 비어있으면 1return 아니면 0리턴으로 
*/
#include <iostream>
#include<string>
#include<stack>
using namespace std;

int solution(string s)
{
    int answer = -1;
    stack<char> stack;
    
    for(int i = 0; i < s.length();i++){
        char c = s[i];
        
        if (stack.empty())
            stack.push(c);
        else{
            if(stack.top() == c)
                stack.pop();
            else{
                stack.push(c);
            }
        }
    }
    
    if(stack.empty())
        return 1;
    else
        return 0;
}