//문제풀이: https://githubseob.tistory.com/308
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<char>v_num = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };

string itos(int num, int n) {
    string ret("");
    while (num > 0) {
        ret += v_num[num % n];
        num /= n;
    }

    reverse(ret.begin(), ret.end());

    return ret;
}

string solution(int n, int t, int m, int p) {
    string answer("");

    int number(1);
    string notation("0");
    for (int idx = 0; idx < m * t; ++idx) {
        if (notation.empty()) {
            notation = itos(number++, n);
        }
        if (idx % m + 1 == p) answer += notation[0];
        notation.erase(0, 1);
    }
    return answer;
}