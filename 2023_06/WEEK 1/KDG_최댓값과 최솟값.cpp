#include <sstream>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

string solution(string s) {
    string result = " ";
    stringstream ss(s);
    vector<int> maxmin = {};
    int num;
    while (ss >> num) {
        maxmin.push_back(num);
    }

    sort(maxmin.begin(), maxmin.end());
    result = to_string(maxmin.front()) + " " + to_string(maxmin.back());
    return result;
}