#include <string>
#include <bitset>
#include <algorithm>

using namespace std;

int solution(int n) {
    string s1 = bitset<32>(n).to_string();
    s1.erase(remove(s1.begin(), s1.end(), '0'), s1.end());

    while (true) {
        n++;
        string s2 = bitset<32>(n).to_string();
        s2.erase(remove(s2.begin(), s2.end(), '0'), s2.end());

        if (s1.size() == s2.size()) {
            return n;
        }
    }
}