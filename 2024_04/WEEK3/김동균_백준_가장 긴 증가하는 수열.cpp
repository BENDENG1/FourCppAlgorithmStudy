#include <iostream>
#include <vector>
// BOJ - 12015 LIS 2
using namespace std;

vector<int> a, ans;

int Solve(int k) {
	int start = 0, End = ans.size() - 1, mid;

	while (start < End) {
		mid = start + (End - start) / 2;

		if (ans[mid] >= k)
			End = mid;
		else start = mid + 1;
	}

	return End;
}

int main(void) {
	int N, idx;

	cin >> N;
	int temp;
	for (int i = 0; i < N; i++)
	{
		cin >> temp;  a.push_back(temp);
	}
	ans.push_back(a.front());

	for (int i = 1; i < N; i++) {
		if (a[i] > ans.back())
			ans.push_back(a[i]);
		else {
			idx = Solve(a[i]);
			ans[idx] = a[i];
		}
	}
	cout << ans.size();

	return 0;
}