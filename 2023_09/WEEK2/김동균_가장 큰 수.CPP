#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 비교 함수 정의
bool compare(string a, string b) {
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> T;

    for (auto a : numbers) {
        T.push_back(to_string(a));
    }

    // 비교 함수를 이용하여 정렬
    sort(T.begin(), T.end(), compare);

    for (auto a : T) {
        answer += a;
    }

    // 만약 가장 큰 수가 0으로 시작하면 "0"으로 반환
    if (answer[0] == '0') {
        return "0";
    }

    return answer;
}