//문제풀이: https://githubseob.tistory.com/370

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string input_string) {
    string answer = "";
    vector<int>cnt(26, 0);
    int alp_idx(input_string[0] - 'a');
    cnt[alp_idx] = 1;
    for (int idx = 1; idx < input_string.size(); ++idx) {
        alp_idx = input_string[idx] - 'a';
        if (input_string[idx - 1] == input_string[idx]) continue;
        else ++cnt[alp_idx];
    }

    for (int idx = 0; idx < 26; ++idx) if (cnt[idx] > 1) answer += idx + 'a';
    if (answer.empty()) answer = "N";
    return answer;
}