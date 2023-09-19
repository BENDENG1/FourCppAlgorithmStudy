//문제풀이: https://githubseob.tistory.com/182

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(int n) {
    vector<string>number = { "1","2","4" };
    string answer("");

    while (n > 0) {
        if (n % 3 == 0) {
            answer += "4";
            --n;
        }
        else answer += to_string(n % 3);
        n /= 3;
    }

    reverse(answer.begin(), answer.end());

    return answer;
}