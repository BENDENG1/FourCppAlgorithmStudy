/*
들어왔습니다, 나갔습니다로 메시지 출력
이름을 바꾸는것은 -> 나간 후 새로운 닉네임으로 혹은 채팅방에서 변경

입장, 퇴장, 변경에 대해서 저장을 한다.

그리고 나중에 일괄적으로 진행을 시킨다.
*/

#include <string>
#include <vector>
#include <sstream>
#include <map>


using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<string> s;
    vector<pair<string,int>> stateUser; //유저의 uid와 입출 상태(입 : 1, 출 : 2)
    map<string,string> idUser; //uid와 아이디 저장 map
    string token;
    char delimeter = ' ';
    
    for(int i = 0 ; i < record.size();i++){
        istringstream iss(record[i]);
        s.clear(); // s초기화
        while(getline(iss,token,delimeter)){
            s.push_back(token);
        }
        if(s[0] =="Enter" || s[0] == "Change")
            idUser[s[1]] = s[2];
        if(s[0] == "Enter")
            stateUser.push_back(make_pair(s[1],1));
        else if(s[0] == "Leave")
            stateUser.push_back(make_pair(s[1],0));
    }
    
    for(int i = 0; i < stateUser.size();i++){
        //입장일때
        if(stateUser[i].second == 1){
            answer.push_back(idUser[stateUser[i].first]+"님이 들어왔습니다.");
        }
        else{ //나갈때
            answer.push_back(idUser[stateUser[i].first]+"님이 나갔습니다.");
        }
    }
    
    return answer;
}