//문제풀이: https://githubseob.tistory.com/318

#include <string>
#include <vector>
#include <cctype>
#include <sstream>
#include <algorithm>
#define pii pair<int, int>
using namespace std;

string lower(string str) {
    string ret("");
    for (int idx = 0; idx < str.size(); ++idx) {
        ret += tolower(str[idx]);
    }
    return ret;
}

pii findNum(string str) {
    int start(0), end(0), prev(-1);
    for (int idx = 0; idx < str.size(); ++idx) {
        if (isdigit(str[idx]) != 0) {
            if (start == 0) start = idx;
            end = idx;
        }
        else if (isdigit(str[idx]) == 0 && end != 0) break;
    }
    return { start, end };
}

bool cmp(string s1, string s2) {
    string head1(""), head2("");
    int number1(0), number2(0);
    int start(0), end(0);

    pii ret = findNum(s1);
    start = ret.first, end = ret.second;

    head1 = lower(s1.substr(0, start));
    number1 = stoi(s1.substr(start, end - start + 1));

    ret = findNum(s2);
    start = ret.first, end = ret.second;

    head2 = lower(s2.substr(0, start));
    number2 = stoi(s2.substr(start, end - start + 1));

    if (head1 == head2) {
        return number1 < number2;
    }
    return head1 < head2;
}

vector<string> solution(vector<string> files) {
    stable_sort(files.begin(), files.end(), cmp);
    return files;
}