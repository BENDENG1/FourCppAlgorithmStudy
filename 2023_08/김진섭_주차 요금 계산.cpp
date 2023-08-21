//문제풀이: https://githubseob.tistory.com/309

#include <string>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    unordered_map<string, int>in;
    map<string, int>total;

    string hour(""), min(""), num(""), IO("");

    for (int idx = 0; idx < records.size(); ++idx) {
        hour = records[idx].substr(0, 2);
        min = records[idx].substr(3, 2);
        num = records[idx].substr(6, 4);
        IO = records[idx].substr(11);

        int time = (stoi(hour)) * 60 + stoi(min);
        if (IO == "IN") {
            in[num] = time;
        }
        else if (IO == "OUT") {
            total[num] += time - in[num];
            in.erase(num);
        }
    }

    for (auto iter = in.begin(); iter != in.end(); ++iter) {
        total[iter->first] += 23 * 60 + 59 - in[iter->first];
    }

    for (auto iter = total.begin(); iter != total.end(); ++iter) {
        int time = iter->second;
        int fee(0);
        if (time <= fees[0]) fee = fees[1];
        else if (time > fees[0]) {
            fee = fees[1] + (time - fees[0] + fees[2] - 1) / fees[2] * fees[3];
        }
        answer.push_back(fee);
    }

    return answer;
}
