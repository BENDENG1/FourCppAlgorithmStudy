//문제풀이: https://githubseob.tistory.com/297

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(int n, long long left, long long right) {
    int y(0), x(0), num(0);
    vector<int> answer;

    for (left; left <= right; ++left) {
        answer.push_back(max(left / n + 1, left % n + 1));
    }

    return answer;
}