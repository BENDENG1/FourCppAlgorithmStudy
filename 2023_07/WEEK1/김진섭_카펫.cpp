//문제풀이: https://githubseob.tistory.com/196

#include <string>
#include <vector>
using namespace std;

vector<int> solution(int brown, int yellow) {
    int idx(0), idx2(0), quotient(0);
    for (idx = 1; idx * idx <= yellow; ++idx) {
        if (yellow % idx == 0) {
            quotient = yellow / idx;
            if ((quotient + 2) * (idx + 2) == brown + yellow) {
                return { quotient + 2, idx + 2 };
            }
        }
    }
}