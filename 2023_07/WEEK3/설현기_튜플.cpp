#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(string s) {
    map<int, int> m;
    for(int i = 1; i < s.size(); i++){
        if(isdigit(s[i])){
            m[stoi(s.substr(i))]++;
            while(isdigit(s[i]))
                i++;
        }
    }
    vector<int> answer(m.size());
    for(auto a : m){
        answer[m.size() - a.second] = a.first;
    }
    return answer;
}