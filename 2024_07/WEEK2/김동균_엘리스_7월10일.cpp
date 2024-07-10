#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    vector<char> temp;
    int answer(0);
    cin >> s;
    for (auto& a : s)
    {
        if (a == '(')
        {
            temp.push_back(a);
        }
        else if (a == ')')
        {
            while (temp.back() != '(')
            {
                answer++;
                temp.pop_back();
            }
            if (temp.back() == '(')
            {
                temp.pop_back();
                answer *= (temp.back() - '0');
                temp.pop_back();
            }
        }
        else
        {
            temp.push_back(a);
        }
    }
    cout << answer+temp.size();
}
