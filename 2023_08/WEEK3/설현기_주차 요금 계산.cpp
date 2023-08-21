#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>

using namespace std;

int getTime(string out, string in) {
    int hourDiff = stoi(out.substr(0, 2)) - stoi(in.substr(0, 2));
    int minuteDiff = stoi(out.substr(3, 2)) - stoi(in.substr(3, 2));
    
    return abs(hourDiff * 60 + minuteDiff);
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<string, vector<string>> getIn; 
    map<string, int> timeOfUse;
    
    for (string record: records) {
        stringstream ss(record);
        string time, carNumber, info;
        ss >> time >> carNumber >> info;
        
        if (info == "IN") getIn[carNumber].push_back(time);
        else {
            string in_time = getIn[carNumber].back();
            getIn[carNumber].pop_back();
            int time_use = getTime(time, in_time);
            timeOfUse[carNumber] += time_use;
        }
    }
    
    for (auto it: getIn) {
        if (!getIn[it.first].empty()) timeOfUse[it.first] += getTime("23:59", getIn[it.first].back());
    }
    
    for (auto it: timeOfUse) {
        if (timeOfUse[it.first] <= fees[0]) answer.push_back(fees[1]);
        else answer.push_back(fees[1] + ceil((double)(timeOfUse[it.first] - fees[0]) / fees[2]) * fees[3]);
    }
    
    return answer;
}