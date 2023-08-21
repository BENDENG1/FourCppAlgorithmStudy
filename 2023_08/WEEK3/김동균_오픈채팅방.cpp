#include <string>
#include <vector>
#include <sstream>
#include <map>
using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    
    vector<pair<string,string>>id;
    map<string,string>m;
    string stat="";
    string userid="";
    string nicname="";
    // 상태, 유저 아이디, 닉네임
    for(auto r:record){
        istringstream ss(r);
        ss>>stat>>userid>>nicname; 
    
        m.insert({userid, nicname});   // 맵에 유저 아이디와 닉네임
        id.push_back({userid,stat}); // 벡터에 유저 아이디와 상태
        if(stat[0]!='L'){
            m[userid]=nicname;
        }// 상태가 Leave가 아닐 경우
    }
    
    for(int i=0; i<record.size(); i++){
        if(id[i].second=="Enter"){
            answer.push_back(m[id[i].first]+"님이 들어왔습니다.");
        }else if(id[i].second=="Leave"){
            answer.push_back(m[id[i].first]+"님이 나갔습니다.");      
        }
    }
    
    return answer;
}