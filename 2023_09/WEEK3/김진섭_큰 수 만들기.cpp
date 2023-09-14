//문제풀이: https://githubseob.tistory.com/197

#include <string>
#include <vector>
using namespace std;

string solution(string number, int k) {
    string answer("");

    int target_size(number.size() - k);
    for (int idx = 0; idx < number.size(); ++idx) {
        int rest_cnt = number.size() - idx;
        while (!answer.empty() && answer.back() < number[idx] && answer.size() + rest_cnt > target_size) {
            answer.pop_back();
        }
        answer += number[idx];
    }

    while (answer.size() > target_size) {
        answer.pop_back();
    }

    return answer;
}