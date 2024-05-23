#include <iostream>
#include <vector>
#include <algorithm>
#define pii pair<int, int>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int X(0);
	cin >> X;
	
	vector<int>DP(X + 1, 1e6);
	DP[1] = 0;
	for (int idx = 1; idx <= X; ++idx) {
		if (idx * 2 <= X) DP[idx * 2] = min(DP[idx] + 1, DP[idx * 2]);
		if (idx * 3 <= X) DP[idx * 3] = min(DP[idx] + 1, DP[idx * 3]);
		if (idx + 1 <= X) DP[idx + 1] = min(DP[idx] + 1, DP[idx + 1]);
	}

	cout << DP[X];
}