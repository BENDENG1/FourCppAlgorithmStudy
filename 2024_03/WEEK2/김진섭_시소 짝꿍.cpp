//문제풀이: https://githubseob.tistory.com/363

#include <vector>
#include <unordered_map>
#define ll long long
using namespace std;

long long solution(vector<int> input) {
    long long answer(0);
    unordered_map<int, ll>weights;

    for (int idx = 0; idx < input.size(); ++idx)
        ++weights[input[idx]];

    for (auto iter = weights.begin(); iter != weights.end(); ++iter) {
        if (iter->second > 1)
            answer += (iter->second) * (iter->second - 1) / 2;
    }

    for (int idx = 0; idx < input.size(); ++idx) {
        if (input[idx] * 2 % 3 == 0)
            answer += weights[input[idx] * 2 / 3];

        if (input[idx] % 2 == 0)
            answer += weights[input[idx] * 1 / 2];

        if (input[idx] * 3 % 4 == 0)
            answer += weights[input[idx] * 3 / 4];
    }

    return answer;
}