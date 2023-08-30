//문제풀이: https://githubseob.tistory.com/316

#include <string>
#include <vector>
#include <set>
using namespace std;

set<string>dict;
char alp[5] = { 'A','E','I','O','U' };

void DFS(int cnt, string word) {
    if (cnt > 4) return;
    for (int idx = 0; idx < 5; ++idx) {
        DFS(cnt + 1, word + alp[idx]);
        dict.insert(word + alp[idx]);
    }
}

int solution(string word) {
    int answer(0);
    DFS(0, "");
    for (auto iter = dict.begin(); iter != dict.end(); ++iter) {
        ++answer;
        if (*iter == word) return answer;
    }    
}