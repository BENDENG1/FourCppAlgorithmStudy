//문제풀이: https://githubseob.tistory.com/195

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> citations) {
    int answer(0), idx(0), cnt(0);

    sort(citations.begin(), citations.end());

    for (idx = 0; idx < citations.size(); ++idx) {
        if (citations[idx] >= citations.size() - idx) {
            return citations.size() - idx;
        }
    }
}