//문제풀이: https://githubseob.tistory.com/192

#include <algorithm>
using namespace std;

int solution(int n, int a, int b)
{
    int idx(1);

    if (a > b) {
        swap(a, b);
    }

    while (1) {
        if (a % 2 == 1 && a + 1 == b) {
            return idx;
        }
        if (a % 2 == 1) {
            a++;
        }
        if (b % 2 == 1) {
            b++;
        }
        a /= 2;
        b /= 2;
        ++idx;
    }
}