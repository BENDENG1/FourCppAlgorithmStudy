#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#define ll long long
using namespace std;

unordered_map<ll, ll>num;
ll answer, S, N;

void DFS(int end, int idx, const vector<int>& nums, ll sum) {
	if (idx == end) {
		if (idx == N) {
			answer += num[S - sum];
		}
		else {
			++num[sum];
		}
		return;
	}
	DFS(end, idx + 1, nums, sum);
	sum += nums[idx];
	DFS(end, idx + 1, nums, sum);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> S;

	vector<int>nums(N, 0);
	for (int idx = 0; idx < N; ++idx) {
		cin >> nums[idx];
	}

	DFS(N / 2, 0, nums, 0);
	DFS(N, N / 2, nums, 0);
	if (S == 0) {
		--answer;
	}
	cout << answer;
}