#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    stack<string>s;
    string input("");
    cin >> input;

    string number("");
    int answer(0);
    for (int idx = 0; idx < input.size(); ++idx) {
        if (input[idx] == '(') {
            s.push(number);
            number.clear();
        }
        else if (input[idx] == ')') {
            if (answer == 0) {
                answer = number.size();
            }
            string num = s.top();
            answer *= (num[num.size() - 1] - '0');
            answer += num.size() - 1;
            s.pop();
        }
        else {
            number += input[idx];
        }
    }
    if (answer == 0) answer = number.size();
    cout << answer;
}
