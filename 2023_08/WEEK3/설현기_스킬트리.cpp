#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    map<char, int> m;
    for(int i = 0; i < skill.length(); i++){
        m[skill[i]] = i + 1;
    }
    for(auto st : skill_trees){
        int cnt = 1;
        bool check = true;
        for(int i = 0; i < st.length(); i++){
            if(m[st[i]] > cnt){
                check = false;
                break;
            }
            else if(m[st[i]] == cnt)
                cnt++;
        }
        if(check)
            answer++;
    }
    return answer;
}