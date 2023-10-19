//문제풀이: https://githubseob.tistory.com/358

#include <string>
#include <vector>
#include <algorithm>
#include <set>
#define ll long long
using namespace std;

vector<ll>init_nums;
vector<char>init_oprs;
set<char>use;

ll answer;

void search() {
    vector<char>order(use.begin(), use.end());

    do {
        vector<ll>nums = init_nums;
        vector<char>oprs = init_oprs;

        for (int cnt = 0; cnt < order.size(); ++cnt) {
            for (int idx = 0; idx < oprs.size();) {
                if (order[cnt] == oprs[idx]) {
                    if (oprs[idx] == '+') nums[idx] = nums[idx] + nums[idx + 1];
                    else if (oprs[idx] == '-') nums[idx] = nums[idx] - nums[idx + 1];
                    else if (oprs[idx] == '*') nums[idx] = nums[idx] * nums[idx + 1];

                    nums.erase(nums.begin() + idx + 1);
                    oprs.erase(oprs.begin() + idx);
                }
                else ++idx;
            }
        }
        ll num = abs(nums[0]);

        answer = max(answer, num);

    } while (next_permutation(order.begin(), order.end()));
}

void init(string expression) {
    string num("");
    for (int idx = 0; idx < expression.size(); ++idx) {
        if (idx + 1 == expression.size()) {
            num += expression[idx];
            init_nums.push_back(stoi(num));
        }
        if (isdigit(expression[idx]) > 0) num += expression[idx];
        else {
            init_nums.push_back(stoi(num));
            init_oprs.push_back(expression[idx]);
            num.clear();
            use.insert(expression[idx]);
        }
    }
}

ll solution(string expression) {
    init_nums = vector<ll>();
    init_oprs = vector<char>();
    use = set<char>();

    init(expression);
    search();

    return answer;
}