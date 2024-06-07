//문제풀이: https://githubseob.tistory.com/387

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int find(vector<int>& parent, int num) {
	if (parent[num] == num) return num;
	return parent[num] = find(parent, parent[num]);
}

void Union(vector<int>& parent, int num1, int num2) {
	num1 = find(parent, num1), num2 = find(parent, num2);
	if (num1 == num2) return;
	if (num1 < num2) swap(num1, num2);
	parent[num1] = num2;
}

bool isUnion(vector<int>& parent, int num1, int num2) {
	if (find(parent, num1) == find(parent, num2)) return true;
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N(0), M(0);
	cin >> N >> M;
	vector<int>parent(N + 1, 0);
	for (int idx = 0; idx <= N; ++idx) parent[idx] = idx;

	for (int idx = 0; idx < M; ++idx) {
		int cmd(0), num1(0), num2(0);
		cin >> cmd >> num1 >> num2;
		if (cmd == 0) Union(parent, num1, num2);
		else if (cmd == 1) isUnion(parent, num1, num2) ? cout << "YES\n" : cout << "NO\n";
	}
}