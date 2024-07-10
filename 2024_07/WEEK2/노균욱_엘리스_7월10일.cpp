#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    vector<char> v;
    int answer(0);
    cin >> s;
    for (auto& c : s)
    {
        if (c == '(')
        {
            v.push_back(c);
        }
        else if (c == ')')
        {
            while (v.back() != '(')
            {
                answer++;
                v.pop_back();
            }
            if (v.back() == '(')
            {
                v.pop_back();
                answer *= (v.back() - '0');
                v.pop_back();
            }
        }
        else
        {
            v.push_back(c);
        }
    }
    cout << answer+v.size();
}
