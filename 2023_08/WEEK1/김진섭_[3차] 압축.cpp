//문제풀이: https://githubseob.tistory.com/307
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    vector<string> alp = { "A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z" };

    unordered_map<string, int>dic;
    for (int idx = 0; idx < 26; ++idx) {
        dic[alp[idx]] = idx + 1;
    }
    msg += " ";
    string str("");
    string prev("");
    for (int idx = 0; idx < msg.size(); ++idx) {
        str += msg[idx];
        if (dic.find(str) == dic.end()) {
            answer.push_back(dic[prev]);
            dic[str] = dic.size() + 1;
            prev = msg[idx];
            str = msg[idx];
        }
        else prev = str;
    }

    return answer;
}