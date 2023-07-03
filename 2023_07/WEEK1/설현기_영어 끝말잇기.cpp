#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer(2, 0);
    map<string, int> m;
    m[words[0]]++;
    for(int i = 1; i < words.size(); i++){
        m[words[i]]++;
        if(m[words[i]] > 1 || words[i-1].back() != words[i].front()){
            answer[0] = i % n + 1;
            answer[1] = i / n + 1;
            break;
        } 
    }
    return answer;
}