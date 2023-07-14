//문제풀이: https://githubseob.tistory.com/299

#include <string>
#include <vector>
#include <map>
#include <cctype>
using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer(0), idx(0), idx2(0);
    map<string, int>db;
    map<int, string>priority;
    for (idx = 0; idx < cities.size(); ++idx) {
        for (idx2 = 0; idx2 < cities[idx].size(); ++idx2) {
            cities[idx][idx2] = toupper(cities[idx][idx2]);
        }
        if (db.find(cities[idx]) != db.end()) {
            answer += 1;
            priority.erase(db[cities[idx]]);
            db[cities[idx]] = idx;
            priority[idx] = cities[idx];
        }
        else {
            answer += 5;
            db[cities[idx]] = idx;
            priority[idx] = cities[idx];
            if (cacheSize < db.size()) {
                auto iter = priority.begin();
                db.erase(iter->second);
                priority.erase(iter);
            }
        }
    }

    return answer;
}