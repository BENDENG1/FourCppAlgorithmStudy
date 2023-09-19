//문제풀이: https://githubseob.tistory.com/342

#include <string>
#include <vector>
#include <algorithm>
#define ll long long
#define INF 1e7
using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer(INF);
    ll sum(0), target(0);
    vector<int>elements(queue1.size() + queue2.size(), 0);

    for (int idx = 0; idx < queue1.size(); ++idx) {
        elements[idx] = queue1[idx];
        target += elements[idx];
    }
    for (int idx = queue1.size(); idx < queue1.size() + queue2.size(); ++idx) {
        elements[idx] = queue2[idx - queue1.size()];
        target += elements[idx];
    }

    target /= 2;

    int left(0), right(0);
    int q1_size(queue1.size()), q2_size(queue2.size());

    while (right < elements.size()) {
        if (sum < target) {
            sum += elements[right++];
        }
        else if (sum == target) {
            if (left < queue1.size() && right < queue1.size()) {
                answer = min(answer, right + q2_size + left);
            }
            else if (left < queue1.size() && right >= queue1.size()) {
                answer = min(answer, left + right - q1_size);
            }
            else if (left > queue1.size()) {
                answer = min(answer, right - q1_size + left);
            }
            sum -= elements[left++];
        }
        else if (sum > target) {
            sum -= elements[left++];
        }
    }

    while (left < elements.size()) {
        sum -= elements[left++];
        if (sum == target) {
            answer = min(answer, left - q2_size);
        }
    }

    if (answer == INF) answer = -1;
    return answer;
}