/*
압축

그냥 계속 가다가 만약에 맵에 존재하지 않으면 그에 대해서 
map에는 insert를 하고 맨뒤 문자를 잘라내고 그다음 answer에다 push_back을 한다.
다만 다음글자가 지정된 곳에서 다시 반복문을 시작해야하므로 i--

그리고 보면 마지막 kakao의 o와 tobe~~애서의 ot를 보면 반복문이 끝나고 또 따로 push_back을 해야함
*/
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    map<string,int> m;
    string s = "";
    
    for(int i = 1 ; i <= 26; i++){
        char c = 'A' + (i - 1);
        s ="";
        s += c;
        m.insert({s,i});
    }
    
    int idx = 27;
    s="";
    for(int i = 0; i < msg.length();i++){
        s.push_back(msg[i]);
        if(m.find(s) == m.end()){
            m.insert({s,idx});
            idx++;
            s.pop_back();
            answer.push_back(m[s]);
            s="";
            i--;
        }
    }
    answer.push_back(m[s]);
    return answer;
}