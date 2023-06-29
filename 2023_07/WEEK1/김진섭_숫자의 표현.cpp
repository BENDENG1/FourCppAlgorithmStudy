//문제풀이: https://githubseob.tistory.com/241

#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer(0), s(1), e(0), sum(0);

    if (n > 2) {
        answer++;
    }

    while (e <= n / 2 + 1) {
        if (sum < n) {
            ++e;
            sum += e;
        }
        else if (sum >= n) {
            sum -= s;
            s++;
        }
        if (sum == n) {
            answer++;
        }
    }
    return answer;
}