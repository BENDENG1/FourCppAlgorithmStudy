#include <cmath>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records)
{
    vector<int> answer;
    map<string, int> m;
    map<string, int> total;

    for (auto r : records)
    {
        istringstream ss(r);

        string stime, number, IO;
        ss >> stime >> number >> IO;

        string hour = stime.substr(0, 2); // 시간을 추출
        string min = stime.substr(3, 2);  // 분을 추출
        int time = stoi(hour) * 60 + stoi(min);

        if (IO == "IN")
        {
            m[number] = time;
        }
        // OUT일 경우 Map(total) 데이터셋에 차량번호에 time을 출차시간과 비교하여
        // 갱신한다. 갱신한 차량번호는 목록에서 제거한다
        else
        {
            if (m.find(number) != m.end())
            {
                total[number] = total[number] + time - m[number];
                m.erase(number);
            }
        }
    }

    // 갱신되지않은, 즉 남아있는 차량은 23시 59분을 기준으로 날린다.
    for (auto entry : m)
    {
        int entryTime = entry.second;
        int duration = 1439 - entryTime; // 하루를 1439분으로 계산하여 날린다.
        total[entry.first] = total[entry.first] + duration;
    }

    for (auto iter : total)
    {
        int time = iter.second;
        int fee(0);
        if (time <= fees[0])
            fee = fees[1];
        else if (time > fees[0])
        {
            fee = fees[1] + (time - fees[0] + fees[2] - 1) / fees[2] * fees[3];
        }
        answer.push_back(fee);
    }

    return answer;
}