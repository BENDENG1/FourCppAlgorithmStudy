//문제풀이: https://githubseob.tistory.com/343

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int>answer(2, 0);
    answer[1] = sequence.size() - 1;
    int left(0), right(0), sum(0);

    while (right < sequence.size()) {
        if (sum < k) {
            sum += sequence[right++];
            continue;
        }
        else if (sum == k) {
            if (answer[1] - answer[0] + 1 > right - 1 - left + 1) {
                answer[1] = right - 1;
                answer[0] = left;
            }
            sum -= sequence[left++];
        }
        else if (sum > k) {
            sum -= sequence[left++];
        }
    }

    while (left < sequence.size()) {
        sum -= sequence[left++];
        if (sum == k) {
            if (answer[1] - answer[0] + 1 > right - 1 - left + 1) {
                answer[1] = right - 1;
                answer[0] = left;
            }
        }
    }

    return answer;
}