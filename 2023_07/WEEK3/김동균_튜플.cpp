#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    vector< vector<int> > v;
    
    // 문자열을 순회하며 튜플의 원소 추출
    for(int i = 1; i < s.size() - 1; i++) {
        vector<int> tmp;
        if(s[i] == '{') {
            string tmp_str = "";
            for(int j = i + 1; j < s.size() - 1; j++) {
                if(s[j] == '}') {
                    i = j; 
                    break;
                }
                
                // ','이 아닌 숫자들을 tmp_str에 저장하여 하나의 튜플 원소로 추출
                if(s[j] != ',') {
                    tmp_str += s[j];
                    if(s[j + 1] == '}' || s[j + 1] == ',') {
                        tmp.push_back(stoi(tmp_str));
                        tmp_str = "";
                    }
                }
            }
            v.push_back(tmp);
        }
    }
    
    int size = 1;
    // v 벡터에서 원소의 길이가 1부터 s의 길이까지 순차적으로 처리
    while(size <= s.size()) {
        for(int i = 0; i < v.size(); i++) {
            if(v[i].size() == size) {
                for(int j = 0; j < v[i].size(); j++) {
                    if(answer.empty()) 
                        answer.push_back(v[i][j]);
                    else {
                        // answer에 없는 원소만 추가
                        bool exist = false;
                        for(int m = 0; m < answer.size(); m++) {
                            if(v[i][j] == answer[m]) {
                                exist = true;
                            }
                        }
                        if(!exist) {
                            answer.push_back(v[i][j]);
                            break;
                        }
                    }
                }
            }
        }
        ++size;
    }
    
    return answer;
}
