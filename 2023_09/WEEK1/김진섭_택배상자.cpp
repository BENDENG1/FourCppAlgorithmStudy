//문제풀이: https://githubseob.tistory.com/332

#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(vector<int> order) {
    int N = order.size();
    int order_idx(0), answer(0), need(0);
    stack<int>stk;

    int box_num = 1;
    while (1) {
        if (order_idx >= N) break;
        need = order[order_idx];
        if (box_num > N && !stk.empty() && stk.top() != need) break;
        if (need == box_num) {
            ++order_idx;
            ++box_num;
            ++answer;
        }
        else if (!stk.empty() && stk.top() == need) {
            ++order_idx;
            ++answer;
            stk.pop();
        }
        else {
            stk.push(box_num++);
        }
    }

    return answer;
}
