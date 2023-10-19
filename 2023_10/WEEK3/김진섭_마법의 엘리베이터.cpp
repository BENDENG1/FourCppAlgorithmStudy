//문제풀이: https://githubseob.tistory.com/359

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int getSum(int num) {
    int ret(0);
    while (num > 0) {
        ret += num % 10;
        num /= 10;
    }
    return ret;
}

int solution(int storey) {
    int answer(getSum(storey));

    for (int num = 0; num <= 150000000; ++num) {
        answer = min(answer, getSum(num) + getSum(abs(num - storey)));
    }

    return answer;
}