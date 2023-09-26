#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <map>

using namespace std;

int getMinutes(string start, string end);


string solution(string m, vector<string> musicinfos) {
    string answer = "";
    string startTime = "";
    string endTime = "";
    string songName = "";
    string songDetail = "";
    int maxTime = 0;
    int time = 0;
    
    for(int i = 0 ; i < m.length();i++){
        if(i + 1 < m.length() && m[i+1] == '#'){
            m[i] = tolower(m[i]);
            m.erase(i+1,1);
        }
    }
    
    for(int i = 0 ; i < musicinfos.size();i++){
        istringstream iss(musicinfos[i]);
        char del = ',';
        
        getline(iss,startTime,del);
        getline(iss,endTime,del);
        getline(iss,songName,del);
        getline(iss,songDetail);
        string detail = "";
        
        for(int j = 0 ; j < songDetail.length();j++){
            if(j + 1 < songDetail.length() && songDetail[j+1] == '#'){
                songDetail[j] = tolower(songDetail[j]);
                songDetail.erase(j+1,1);
            }
        }
        time = getMinutes(startTime,endTime);
        for(int j = 0 ; j < time;j++){
            detail += songDetail[j % songDetail.length()];
        }
        //캬 이거 그냥 detail.find(m) && maxTime < time 이렇게만 적어서 안된거였누..
        if(detail.find(m) != std::string::npos && maxTime < time){
            maxTime = time;
            answer = songName;
        }
    }
    
    if(answer == ""){
        return "(None)";
    }
    return answer;
}

int getMinutes(string start, string end){
    int startHour = stoi(start.substr(0,2));
    int startMinute = stoi(start.substr(3,2));
    int endHour = stoi(end.substr(0,2));
    int endMinute = stoi(end.substr(3,2));
    return (endHour - startHour) * 60 + endMinute - startMinute;
}




/////// 아래는 이상한 풀이.. 그래도 잊지말자고 push합니다.
/*
음은 12개 

1분에 1개씩 음이 재생되며

일치x -> "(None)"

음 결국 전체를 돌면서 맞는게 있다면 진행을 한다는 것이 문제 아닌가?
sort때려버리고 진행하면 어떨까 싶음 (문자열을 쪼개는것을 선행을 기준으로)
*/
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <map>

using namespace std;

int getMinutes(string start, string end);

bool checkValidate(map<string,int> musicMap,string detail);
// bool check(map<string,int> infoMap,string music);

bool allKeysZero(const map<string, int>& m) {
    for (const auto& pair : m) {
        if (pair.second != 0) {
            return false;
        }
    }
    return true;
}

string solution(string m, vector<string> musicinfos) {
    string answer = "";
    string startTime = "";
    string endTime = "";
    string songName = "";
    string songDetail = "";
    int maxTime = 0;
    map<string,int> musicMap;
    //map<string,int> infoMap;
    int time = 0;
    
    for(int i = 0 ; i < m.length();i++){
        if(i + 1 < m.length() && m[i+1] == '#'){
            string tmp =m.substr(i,2);
            musicMap[tmp]++;
            i++;
        }else{
            musicMap[string(1,m[i])]++;
        }
    }
    
    for(int i = 0 ; i < musicinfos.size();i++){
        istringstream iss(musicinfos[i]);
        char del = ',';
        
        getline(iss,startTime,del);
        getline(iss,endTime,del);
        getline(iss,songName,del);
        getline(iss,songDetail);
        
        time = getMinutes(startTime,endTime);
        //여기서 #에 대한 처리도 해줘야함
        int idx = 0;
        for(int j = 0 ; j < songDetail.length();j++){
            if(j + 1 < songDetail.length() && songDetail[j+1] =='#'){
                idx++;
                j++;
            }else{
                idx++;
            }
            if(idx == time){
                songDetail = songDetail.substr(0,j);
                break;
            }
        }
        //판별을 해주고 있다면 진행완료 -> 이것은 map의 갯수를 값만 넘겨줘서 다 지워지면 진행 완료
        if(checkValidate(musicMap,songDetail) && maxTime < time) {
            maxTime = time;
            answer = songName;
        }
        // infoMap.clear();
        
        // cout<<startTime<<"\n"<<endTime<<"\n"<<songName<<"\n"<<songDetail<<"\n\n\n";
    }
    
    if(answer == ""){
        return "(None)";
    }
    return answer;
}

int getMinutes(string start, string end){
    int startHour = stoi(start.substr(0,2));
    int startMinute = stoi(start.substr(3,2));
    int endHour = stoi(end.substr(0,2));
    int endMinute = stoi(end.substr(3,2));
    return (endHour - startHour) * 60 + endMinute - startMinute;
}

bool checkValidate(map<string,int> musicMap,string detail){
    string tmp = "";
    bool allContain = true;
    for(int i = 0 ; i < detail.length();i++){
        if(i + 1 < detail.length() && detail[i+1] == '#'){
            tmp =detail.substr(i,2);
            i++;
        }else{
            tmp = string(1,detail[i]);
        }
        if(musicMap[tmp] > 0){
            musicMap[tmp]--;
            if(allKeysZero(musicMap)){
                return true;
            }
        }else{
            allContain = false;
        }
    }
    if(allContain){
        return true;
    }
    for(auto iter : musicMap){
        if(iter.second != 0)
            return false;
    }
    return true;
}



// bool check(map<string,int> infoMap,string music){
//     string tmp = "";
//     for(int i = 0 ; i < music.length();i++){
//         if(i + 1 < music.length() && music[i+1] == '#'){
//             tmp =music.substr(i,2);
//             i++;
//         }else{
//             tmp = string(1,music[i]);
//         }
//         if(infoMap[tmp] > 0){
//             infoMap[tmp]--;
//         }
//     }

//     for(auto iter : infoMap){
//         if(iter.second != 0)
//             return false;
//     }
//     return true;
// }
