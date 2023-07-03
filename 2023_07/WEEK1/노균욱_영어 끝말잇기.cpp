#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    int turn = 0;
    
    for(int i = 1; i < words.size() ;i++){
        if(words[i][0] != words[i - 1].back()){
            answer.push_back(i % n + 1);
            answer.push_back((i / n) + 1);
            return answer;
        }  
        for(int j = 0; j < i;j++){
            if(words[i] == words[j]){
                answer.push_back(i % n + 1);
                answer.push_back((i / n) + 1);
                return answer;
            }
        }
    }
    
    answer.push_back(0);
    answer.push_back(0);
    return answer;
}