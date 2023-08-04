#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

bool isPrefix(string str1, string str2)
{
    if (str1.length() > str2.length())
    {
        return false;
    }
    for (size_t i = 0; i < str1.length(); ++i)
    {
        if (str1[i] != str2[i])
        {
            return false;
        }
    }
    return true;
}

bool solution(vector<string> phone_book)
{
    unordered_map<string, bool> m;

    for (string &number : phone_book)
    {
        m[number] = true;
    }

    // 해시맵을 순회하며 접두사인지 확인
    for (auto entry : m)
    {
        const string number = entry.first;

        for (size_t i = 1; i < number.length(); ++i)
        {
            string prefix = number.substr(0, i);
            if (m.find(prefix) != m.end() && !isPrefix(number, prefix))
            {
                return false;
            }
        }
    }

    return true;
}