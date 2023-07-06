//문제풀이: https://githubseob.tistory.com/254

#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(int n, vector<string> words) {
    char prev(words[0][0]); // 이전 단어 끝글자 변수
    map<string, int>log; // 이미 말한 단어인지

    for (int idx = 0; idx < words.size(); ++idx) {
        if (log[words[idx]] == 1 || prev != words[idx][0] || words[idx].size() == 1) {
            return { idx % n + 1 , idx / n + 1 };
            // 이미 말한 단어인지 or 끝-첫글자가 다른지 or 1글자 인지
        }
        log[words[idx]]++; // 단어 횟수 +1
        prev = words[idx].back(); // 끝단어 저장
    }
    return { 0,0 };
}