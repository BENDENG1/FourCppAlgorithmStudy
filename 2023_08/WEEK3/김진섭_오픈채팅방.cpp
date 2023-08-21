//문제풀이: https://githubseob.tistory.com/180

#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#define pis pair<int, string>
using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<pis>logs;
    unordered_map<string, string>uid;
    for (int idx = 0; idx < record.size(); ++idx) {
        istringstream iss(record[idx]);
        string nickname(""), s_uid(""), s_IO("");
        iss >> s_IO >> s_uid >> nickname;

        if (s_IO == "Enter") {
            logs.push_back({ 0, s_uid });
            uid[s_uid] = nickname;
        }
        else if (s_IO == "Leave") {
            logs.push_back({ 1, s_uid });
        }
        else if (s_IO == "Change") {
            uid[s_uid] = nickname;
        }
    }

    for (int idx = 0; idx < logs.size(); ++idx) {
        string str("");
        str += uid[logs[idx].second];
        if (logs[idx].first == 0) {
            str += "님이 들어왔습니다.";
        }
        else if (logs[idx].first == 1) {
            str += "님이 나갔습니다.";
        }
        answer.push_back(str);
    }

    return answer;
}