/*
재귀를 돌면서 음.. 하는게 좋을듯

(과 )의 갯수가 맞는 순간은 거기까지는 일단 맞는거임 

계속 맞춰나가면서 뒤에를 재귀로 채워버리면 됨

*/
#include <string>
#include <vector>

using namespace std;

bool check(string p){
    int num = 0;
    for(int i = 0 ; i < p.length();i++){
        if(p[i] == '(')
            num++;
        else
            num--;
        if(num < 0)
            return false;
    }
    return true;
}

string solution(string p) {
    string answer = "";
    string u = "",v="";
    int left = 0, right = 0;
    
    if(p == "")
        return answer;
    
    for(int i = 0 ; i < p.length();i++){
        if(p[i] == '(')
            left++;
        else
            right++;
        
        if(left == right){
            u = p.substr(0,i+1);
            v = p.substr(i+1);
            break;
        }
    }
    
    if(check(u))
        answer = u + solution(v);
    else{
        answer = "(" + solution(v) + ")";
        for(int i = 1; i < u.length() - 1;i++){
            if(u[i] == '(') 
                answer += ')';
            else
                answer += '(';
        }
    }
    return answer;
}