#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    vector<char> test;
    for (auto a : skill)
        test.push_back(a);

    for (auto Tree : skill_trees) {
        vector<char> temp = test;
        bool Ischeck = false;
        for (int i = 0; i < Tree.size(); i++) {
            if (temp.empty())
                break;
            else if (temp.front() == Tree[i]) {
                temp.erase(temp.begin());
            }
            else if (find(temp.begin(), temp.end(), Tree[i]) != temp.end()) {
                Ischeck = true;
            }
        }
        if (!Ischeck)
            answer++;
    }
    return answer;
}