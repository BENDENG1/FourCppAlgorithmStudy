#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;


int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int N;
    int ans1(0);
    int ans2 (0);
    int sum (0);
    int zero(0);
    int one(0);
    priority_queue<int> q;
    priority_queue<int, vector<int>, greater<int>> q2;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int T;
        cin >> T;
        if (T > 1)q.push(T);
        else if (T == 1)one++;
        else if (T == 0)zero++;
        else q2.push(T);
    }
    while (!q.empty()) {
        int front;
        int back;
        front = q.top();
        if (q.size() != 1) {
            q.pop();
            back = q.top();
            ans1 += front * back;
            q.pop();
        } //그 뒤 남은 수가 짝수 일경우 작은수 그 다음수로 값 출력
        else {
            ans1 += front;
            q.pop();
        }

    }
    while (!q2.empty()) {
        int front2;
        int back2;
        front2 = q2.top();
        if (zero > 0) {               //zero가 존재할때
            if (q2.size() == 1) {
                q2.pop();
            }
            else if (q2.size() != 0) {
                q2.pop();
                back2 = q2.top();
                ans2 += front2 * back2;
                q2.pop();
            }
        }
        else { //zero가 없을때
            if (q2.size() == 1) {
                ans2 += front2;
                q2.pop();
            }
            else  if (q2.size() != 0) {
                q2.pop();
                back2 = q2.top();
                ans2 += front2 * back2;
                q2.pop();
            }
        }
    }
    sum = ans1 + ans2 + one;
    cout << sum;
}