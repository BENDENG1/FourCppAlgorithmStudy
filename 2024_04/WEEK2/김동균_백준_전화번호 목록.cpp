#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

bool isPrefix(string str1, string str2) {
    if (str1.length() > str2.length()) {
        return false;
    }
    for (size_t i = 0; i < str1.length(); ++i) {
        if (str1[i] != str2[i]) {
            return false;
        }
    }
    return true;
}

bool solution(vector<string> phone_book) {
    unordered_map<string, bool> m;

    // 전화번호를 해시맵에 저장
    for (string number : phone_book) {
        m[number] = true;
    }

    // 해시맵을 순회하며 접두사인지 확인
    for (auto entry : m) {
        const string number = entry.first;

        for (size_t i = 1; i < number.length(); ++i) {
            string prefix = number.substr(0, i);
            if (m.find(prefix) != m.end()) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    int t; // 테스트 케이스의 개수
    cin >> t;

    while (t--) {
        int n; // 전화번호의 수
        cin >> n;
        vector<string> phone_book(n);

        for (int i = 0; i < n; ++i) {
            cin >> phone_book[i];
        }

        if (solution(phone_book)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
