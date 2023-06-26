#include <string>
#include <vector>
#include <cctype>
using namespace std;

string solution(string s) {
    s[0] = toupper(s[0]);
    for (int idx = 1; idx < s.size(); ++idx) {
        if (s[idx - 1] == ' ' && s[idx] != ' ') {
            s[idx] = toupper(s[idx]);
        }
        else {
            s[idx] = tolower(s[idx]);
        }
    }

    return s;
}