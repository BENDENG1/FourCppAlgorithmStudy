//문제풀이: https://githubseob.tistory.com/279

#include <string>
#include <numeric>
#include <vector>

using namespace std;

int solution(vector<int> arr) {
    int answer(1), idx(0);

    for (idx = 0; idx < arr.size(); ++idx) {
        answer = lcm(answer, arr[idx]);
    }
    return answer;
}
