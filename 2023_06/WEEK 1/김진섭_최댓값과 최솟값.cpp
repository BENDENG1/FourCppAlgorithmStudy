#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#define MAX 2147483647
#define MIN -2147483648
using namespace std;

string solution(string s) {
    string answer(""), num("");
    int min_num(MAX), max_num(MIN);
    istringstream istr(s);

    while (getline(istr, num, ' ')) {
        min_num = min(stoi(num), min_num);
        max_num = max(stoi(num), max_num);
    }

    answer += to_string(min_num);
    answer += " ";
    answer += to_string(max_num);

    return answer;
}