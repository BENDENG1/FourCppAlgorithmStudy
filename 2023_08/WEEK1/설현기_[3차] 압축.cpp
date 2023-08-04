#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    map<string, int> dict;
    int num = 1;
    for(char c = 'A'; c <= 'Z'; c++){
        string str = "";
        str += c;
        dict[str] = num++;
    }
    
    string cur = "";
    for(int i = 0; i < msg.length(); i++){
        cur += msg[i];
        if(dict.find(cur) == dict.end()){
            dict[cur] = num++;
            cur = cur.substr(0, cur.length() - 1);
            answer.push_back(dict[cur]);
            cur = "";
            i--;
        }
    }
    answer.push_back(dict[cur]);
    return answer;
}