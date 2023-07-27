//문제풀이: https://githubseob.tistory.com/188

#include <string>
#include <vector>
#include <cctype>
#include <algorithm>
#include <map>
using namespace std;

map<string, int>m_str1;
map<string, int>m_str2;

void get_map(string str, map<string, int>& m_str) {
    string elem("");
    for (int idx = 1; idx < str.size(); ++idx) {
        if (isalpha(str[idx - 1]) != false && isalpha(str[idx]) != false) {
            elem.clear();
            elem += tolower(str[idx - 1]);
            elem += tolower(str[idx]);

            ++m_str[elem];
        }
    }
}

int get_int() {
    int cnt_elem(0), ret(0);
    string elem("");
    for (auto iter1 = m_str1.begin(); iter1 != m_str1.end(); ++iter1) {
        elem = iter1->first;

        if (m_str2[elem] > 0) {
            cnt_elem = min(m_str1[elem], m_str2[elem]);
            ret += cnt_elem;
            m_str1[elem] -= cnt_elem;
            m_str2[elem] -= cnt_elem;
        }
    }
    return ret;
}

int get_union(map<string, int>& m_str) {
    int cnt_elem(0), ret(0);
    string elem("");
    for (auto iter1 = m_str.begin(); iter1 != m_str.end(); ++iter1) {
        elem = iter1->first;
        cnt_elem = iter1->second;
        if (cnt_elem > 0) {
            ret += cnt_elem;
        }
    }

    return ret;
}

int solution(string str1, string str2) {
    int answer(0), answer1(0), answer2(0);

    get_map(str1, m_str1);
    get_map(str2, m_str2);

    answer1 = get_int();
    answer2 = answer1;

    answer2 += get_union(m_str1);
    answer2 += get_union(m_str2);

    if (answer2 == 0) return 65536;
    answer = (answer1 * 65536) / answer2;

    return answer;
}