//문제풀이: https://githubseob.tistory.com/296

#include <string>
#include <vector>
#include <set>
using namespace std;

int solution(vector<int> elements) {
    int idx(0), idx2(0);
    set<int>answer;
    vector<int>sum(elements.size());

    for (idx = 0; idx + 1 < elements.size(); ++idx) {
        for (idx2 = 0; idx2 < elements.size(); ++idx2) {
            sum[idx2] += elements[(idx + idx2) % elements.size()];
            answer.insert(sum[idx2]);
        }
    }
    answer.insert(sum[0] + elements.back());

    return answer.size();
}