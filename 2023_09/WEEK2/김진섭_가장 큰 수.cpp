//문제풀이: https://githubseob.tistory.com/142

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(string num1, string num2) {
    return num1 + num2 > num2 + num1;
}

string solution(vector<int> numbers) {
    string answer("");
    vector<string>nums(numbers.size(), " ");

    for (int idx = 0; idx < nums.size(); ++idx)
        nums[idx] = to_string(numbers[idx]);

    sort(nums.begin(), nums.end(), cmp);

    for (int idx = 0; idx < nums.size(); ++idx)
        answer += nums[idx];

    if (answer[0] == '0') return "0";
    return answer;
}