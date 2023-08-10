//문제풀이: https://githubseob.tistory.com/306

#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#define ll long long
using namespace std;

int solution(int n, int k) {
    int answer(0);
    string num("");
    while (n > 0) {
        num += to_string(n % k);
        n /= k;
    }

    reverse(num.begin(), num.end());

    istringstream iss(num);
    string substr("");

    while (getline(iss, substr, '0')) {
        if (substr.empty()) continue;
        ll subnum(stoll(substr));
        bool flag(false);
        if (subnum == 1) continue;
        for (ll idx = 2; idx * idx <= subnum; ++idx) {
            if (subnum % idx == 0) {
                flag = true;
                break;
            }
        }
        if (flag == false) {
            ++answer;
        }
    }

    return answer;
}