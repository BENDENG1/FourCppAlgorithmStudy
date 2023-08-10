//문제풀이: https://githubseob.tistory.com/139

#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

bool cmp(string& s1, string& s2) {
    return s1.size() < s2.size();
}

bool solution(vector<string> phone_book) {
    sort(phone_book.begin(), phone_book.end(), cmp);
    unordered_set<string>num;
    string str("");
    for (int idx = 0; idx < phone_book.size(); ++idx) {
        str.clear();
        for (int idx2 = 0; idx2 < phone_book[idx].size(); ++idx2) {
            str += phone_book[idx][idx2];
            if (num.find(str) != num.end()) return false;
        }
        num.insert(str);
    }

    return true;
}