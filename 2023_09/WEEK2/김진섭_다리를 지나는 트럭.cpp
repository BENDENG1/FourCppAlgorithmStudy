//문제풀이: https://githubseob.tistory.com/336

#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int br_len, int max_weight, vector<int> trucks) {
    int max_cnt(br_len), truck_cnt(0), weight(0), front_truck(0);
    int time(1), prev_time(0);
    queue<int>in_time;

    for (int idx = 0; idx < trucks.size(); ++idx) {
        while (truck_cnt >= max_cnt || weight + trucks[idx] > max_weight) {
            time = in_time.front() + br_len;
            in_time.pop();
            weight -= trucks[front_truck++];
            --truck_cnt;
        }
        if (prev_time >= time) time = prev_time + 1;
        if (idx + 1 == trucks.size()) return time + br_len;
        in_time.push(time);
        ++truck_cnt;
        weight += trucks[idx];
        prev_time = time;
    }
}