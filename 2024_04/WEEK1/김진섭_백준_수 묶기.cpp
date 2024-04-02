//문제풀이: https://githubseob.tistory.com/85

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N(0);
	cin >> N;
	vector<int>num(N, 0);
	priority_queue<int, vector<int>, greater<int>>minus;
	priority_queue<int>plus;

	int sum(0);
	for (int idx = 0; idx < N; ++idx) {
		cin >> num[idx];
		if (num[idx] <= 0) {
			minus.push(num[idx]);
		}
		else if (num[idx] == 1) {
			sum += 1;
		}
		else if (num[idx] > 0) {
			plus.push(num[idx]);
		}
	}

	int num1(0);
	while (!minus.empty()) {
		num1 = minus.top();
		minus.pop();
		if (minus.empty()) sum += num1;
		else {
			num1 *= minus.top();
			minus.pop();
			sum += num1;
		}
	}

	while (!plus.empty()) {
		num1 = plus.top();
		plus.pop();
		if (plus.empty()) sum += num1;
		else {
			num1 *= plus.top();
			plus.pop();
			sum += num1;
		}
	}

	cout << sum;
}