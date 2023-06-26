#include <string>
#include <vector>
#include <cctype>
#include <algorithm> 

using namespace std;

string solution(string s) {
    string answer = "";

    transform(s.begin(), s.end(), s.begin(), ::tolower);

    s[0] = toupper(s[0]);
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == ' ') {
            s[i + 1] = toupper(s[i + 1]);
        }
    }

    answer = s;
    return answer;
}