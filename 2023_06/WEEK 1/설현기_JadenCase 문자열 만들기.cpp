#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";

    for (int i = 0; i < s.size(); i++) {
        if ((isalpha(s[i]) && i == 0) || (isalpha(s[i]) && s[i - 1] == ' ')) {
            s[i] = toupper(s[i]);
        }
        else {
            s[i] = tolower(s[i]);
        }
    }
    answer = s;
    return answer;
}