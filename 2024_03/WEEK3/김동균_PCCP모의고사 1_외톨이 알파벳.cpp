#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string input_string) {
    string answer = "";
    vector<char> temp;
    temp.push_back(input_string[0]);
    for (int i = 1; i < input_string.size(); i++) {
        auto it = find(temp.begin(), temp.end(), input_string[i]);
        if (temp.back() == input_string[i]) {
            temp.push_back(input_string[i]);
        }
        else if (temp.back() != input_string[i] && it == temp.end()) {
            temp.push_back(input_string[i]);
        }
        else {
            temp.push_back(input_string[i]);
            auto it2 = find(answer.begin(), answer.end(), input_string[i]);
            if (it2 == answer.end())
                answer += input_string[i];
        }
    }
    sort(answer.begin(), answer.end());
    //temp 값에다가 넣기
    //temp 값에 마지막 원소와 동일하다면 넣기
    //만약 마지막 원소와 동일하지 않지만 temp에 해당 값이 없다면 넣기
    //erase
    if(answer.empty())
        return "N";
    return answer;
}