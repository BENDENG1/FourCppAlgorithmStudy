/*
외톨이 알파벳 

2회이상 나타난 2개 이상 

맵을 써야겠다.
*/
#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(string input_string) {
    string answer = "";
    map<char,int> alpha;
    
    for(int i = 0 ; i < input_string.length();i++){
        if(alpha.find(input_string[i]) == alpha.end()){
            alpha[input_string[i]] = i;
        }else{
            if(alpha[input_string[i]] != i - 1){
                alpha[input_string[i]] = -1;
            }else{
                alpha[input_string[i]] = i;
            }
        }
    }
    
    for(int i = 0 ; i < 26;i++){
        if(alpha[(char)('a' + i)] == -1)
            answer += (char)('a' + i);
    }
    
    if(answer.length() == 0)
        return "N";
    return answer;
}