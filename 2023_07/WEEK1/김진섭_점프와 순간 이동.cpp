//문제풀이: https://githubseob.tistory.com/264

using namespace std;

int solution(int n)
{
    int cnt(0);
    while (n > 0) {
        if (n % 2 == 1) {
            n -= 1;
            cnt++;
        }
        if (n % 2 == 0) {
            n /= 2;
        }
    }

    return cnt;
}
