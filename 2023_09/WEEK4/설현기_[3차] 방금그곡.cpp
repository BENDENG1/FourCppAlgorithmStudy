#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

void convert(string &sheet) {
    map<char, char> m;
    m.insert({'C', 'Q'});
    m.insert({'D', 'R'});
    m.insert({'F', 'S'});
    m.insert({'G', 'T'});
    m.insert({'A', 'U'});
    
    for(int i=0; i<sheet.length(); i++) {
        if(sheet[i]=='#') {
            sheet[i-1]=m[sheet[i-1]];
            sheet.erase(sheet.begin()+i);
            i--;
        }
    }
    
}

string solution(string m, vector<string> musicinfos) {
    string answer = "(None)";

    int answerPlayTime = -1;
    
    for(int i = 0; i < musicinfos.size(); i++) {
        string title;
        string sheet;
        int playTime=0;
    
        playTime += (musicinfos[i][6] - '0') * 600;
        playTime += (musicinfos[i][7] - '0') * 60;
        playTime += (musicinfos[i][9] - '0') * 10;
        playTime += musicinfos[i][10] - '0';

        playTime -= (musicinfos[i][0] - '0') * 600;
        playTime -= (musicinfos[i][1] - '0') * 60;
        playTime -= (musicinfos[i][3] - '0') * 10;
        playTime -= musicinfos[i][4] - '0';
        
        for(int j = 12; j < musicinfos[i].size(); j++) {
            if(musicinfos[i][j]==',') {
                title = musicinfos[i].substr(12, j-12);
                sheet = musicinfos[i].substr(j+1);
                break;
            }
        }
        
        convert(sheet);
        
        string radio;
        int idx = 0; 
        
        for(int j = 0; j < playTime; j++) {
            radio += sheet[idx++];
            if(idx == sheet.length())
                idx = 0;
        }
        
        convert(m);
        
        if(radio.find(m) != string::npos) { 
            if(answerPlayTime < playTime) { 
                answerPlayTime = playTime; 
                answer = title;
            }
        }
    }
    return answer; 
}