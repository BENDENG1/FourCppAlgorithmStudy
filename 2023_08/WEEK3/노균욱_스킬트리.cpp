/*
맵써서 인덱스 안맞으면 퇴출
*/
#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    map<char,int> m;
    
    for(int i = 0; i < skill.length();i++){
        m[skill[i]] = i + 1;
    }
    
    for(int i = 0; i < skill_trees.size();i++){
        int idx = 1;
        int flag = 0;
        for(int j = 0; j < skill_trees[i].length();j++){
            if(m[skill_trees[i][j]] != 0){
                if(m[skill_trees[i][j]] != idx){
                    flag = 1;
                    break;
                }
                idx++;
            }
        }
        if(flag == 0) answer++;
    }
    return answer;
}