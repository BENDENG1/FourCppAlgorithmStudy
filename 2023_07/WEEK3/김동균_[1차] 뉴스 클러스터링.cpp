#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;

int solution(string str1, string str2)
{
    double answer = 0;
    vector<string> v1;
    vector<string> v2;

    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);

    for (int i = 0; i < str1.size() - 1; i++)
    {
        if (isalpha(str1[i]) && isalpha(str1[i + 1]))
        {
            string s = str1.substr(i, 2);
            v1.push_back(s);
        }
    }

    for (int i = 0; i < str2.size() - 1; i++)
    {
        if (isalpha(str2[i]) && isalpha(str2[i + 1]))
        {
            string s = str2.substr(i, 2);
            v2.push_back(s);
        }
    }
    vector<string> temp;
    for (auto a : v1)
    {
        auto it = find(v2.begin(), v2.end(), a);
        if (it != v2.end())
        {
            temp.push_back(a);
            v2.erase(it);
        }
    }

    for (auto a : v2)
        v1.push_back(a);

    double t = static_cast<double>(temp.size()) / v1.size();
    answer = t * 65536;

    if (v1.size() == 0)
    {
        return 65536;
    }

    return answer;
}