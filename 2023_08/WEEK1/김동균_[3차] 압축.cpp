#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

vector<int> solution(string msg)
{
    vector<int> answer;
    unordered_map<string, int> index;

    for (auto c = 'A'; c <= 'Z'; ++c)
    {
        string s(1, c);         // char문자열 c를 스트링으로 변환
        index[s] = c - 'A' + 1; // 값은 1부터 시작하는 것으로 가정합니다.
    }                           // 색인을 위한 map 생성

    int Newindex = 27;

    string current;
    for (char c : msg)
    {
        current += c;
        if (index.find(current) == index.end())
        {
            answer.push_back(index[current.substr(0, current.length() - 1)]);
            index[current] = Newindex++;
            current = c;
        }
    }
    if (!current.empty())
    {
        answer.push_back(index[current]);
    }
    return answer;
}