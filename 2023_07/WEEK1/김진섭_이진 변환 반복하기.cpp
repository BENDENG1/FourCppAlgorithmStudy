//문제풀이: https://githubseob.tistory.com/240

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string stob(int num) {
    string binary("");
    while (num > 0) {
        binary += to_string(num % 2);
        num /= 2;
    }
    reverse(binary.begin(), binary.end());
    return binary;
}

vector<int> solution(string s) {
    int idx(0), zero(0);
    vector<int> answer(2, 0);

    while (s != "1") {
        while (s.find('0') != -1) {
            s.erase(find(s.begin(), s.end(), '0'));
            zero++;
        }
        answer[0]++;
        answer[1] += zero;

        s = stob(s.size());
        zero = 0;
    }

    return answer;
}