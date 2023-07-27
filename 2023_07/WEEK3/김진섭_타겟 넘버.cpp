//문제풀이: https://githubseob.tistory.com/138

#include <string>
#include <vector>

using namespace std;

vector<int>number;
int answer, target_num;

void DFS(int idx, int sum) {
    if (idx == number.size()) {
        if (sum == target_num) ++answer;
        return;
    }

    DFS(idx + 1, sum - number[idx]);
    DFS(idx + 1, sum + number[idx]);
}

int solution(vector<int> numbers, int target) {
    target_num = target;
    number = numbers;
    DFS(0, 0);
    return answer;
}