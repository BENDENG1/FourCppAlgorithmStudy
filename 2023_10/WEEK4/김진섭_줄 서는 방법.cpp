//문제풀이: https://githubseob.tistory.com/362

#include <string>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

vector<int> solution(int n, long long k) {
    vector<int>answer(n, 0);
    vector<int>number(n + 1, 0);
    vector<ll>factorial(n, 0);
    --k;

    for (int idx = 0; idx < n; ++idx) number[idx] = idx + 1;

    ll num(2);
    if (n > 1) factorial[n - 2] = 1;
    for (int idx = n - 3; idx >= 0; --idx) {
        factorial[idx] = factorial[idx + 1] * num;
        ++num;
    }

    for (int idx = 0; idx < n; ++idx) {
        if (factorial[idx] == 0) answer[idx] = number[0];
        else {
            answer[idx] = number[k / factorial[idx]];
            number.erase(number.begin() + k / factorial[idx]);
            k -= k / factorial[idx] * factorial[idx];
        }
    }

    return answer;
}