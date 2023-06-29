/*
그냥 닫는 갯수가 순서대로 카운팅할때 마다 더 크면 false
그리고 나중에 열고 닫는 괄호가 갯수다르면 false
*/
#include <string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    int open = 0; 
    int close = 0;
    
    for(int i = 0; i < s.length();i++){
        if(s[i] == '(') open ++;
        else if (s[i] == ')') close++;
        
        if(open < close){
            answer = false;
            break;
        }
    }
    if(open != close)
        answer = false;
    

    return answer;
}