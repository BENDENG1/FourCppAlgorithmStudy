#include <cctype>
#include <algorithm>
#include <string>
#include <iostream>
#include <queue>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    queue<char> test;

    for(int i=0;i<s.size();i++){
      if(s[i]=='('){
        test.push(s[i]);
      }else if(s[i]==')'){
        if(test.empty()){
          answer=false;
            
        }else{
          test.pop();
        }
      }
    }
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    if(!test.empty())
      answer = false;
    return answer;
}