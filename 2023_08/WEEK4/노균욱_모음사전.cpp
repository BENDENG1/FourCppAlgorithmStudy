/*
모음사전 AEIOU만을 사용하여 만들 수 있는 길이 5이하의 단어 수록
A -> AA -> AAA -> AAAA-> AAAAA -> AAAAE -> AAAAI -> AAAAO -> AAAAU -> ...-> UUUUU
AUUUU -> E EUUUU -> I 를 보고 느끼는 것은dfs다. 
*/
#include <string>
#include <vector>

using namespace std;

int cnt = 0;
int answer = 0;
string vowel = "AEIOU";

void dfs(string s,string word) {
    cnt++;
    if (s == word) {
        answer = cnt;
        return;
    }
    if (s.length() >= 5) return;
    
    for (int i=0; i<5; i++) {
        dfs(s + vowel[i],word);
    }
    
}

int solution(string word) {
    dfs("",word);
    return answer - 1;
}