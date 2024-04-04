#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

string solution(string input_string) {
    string answer = "";
    vector<char> arr;
    arr.push_back(input_string[0]);

    // 뭉쳐있는 알파벳들 중복 제거
    for (int i = 1; i < input_string.length(); i++) {
        if (input_string[i] != arr.back()) {
            arr.push_back(input_string[i]);
        }
    }

    // 배열 전체의 모든 중복 요소 제거하고 알파벳 순 정렬
    vector<char> set(arr.begin(), arr.end());
    sort(set.begin(), set.end());
    set.erase(unique(set.begin(), set.end()), set.end());

    for (char i : set) {
        int count = 0;
        for (char j : arr) {
            // set 배열과 arr 배열의 요소가 같으면 count 증가
            if (i == j) count++;
        }
        // 카운트가 1을 초과하면 외톨이 알파벳
        if (count > 1) answer += i;
    }

    
    if(answer.empty())
        return "N";
    else
        return answer;
}