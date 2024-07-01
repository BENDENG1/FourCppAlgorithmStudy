#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int N(0), K(0);
	cin >> N >> K;

	vector<pair<int, int>>item(N+1);
	vector<vector<int>>DP(N+1, vector<int>(K+1, 0));

	for (int idx = 0; idx < N; ++idx) {
		int W(0), V(0);
		cin >> item[idx].first >> item[idx].second;
	}

	sort(item.begin(), item.end());
	
	int answer(0);
	for (int idx = 1; idx <= N; ++idx) {
		int W = item[idx].first;
		int V = item[idx].second;
		for (int weight = 1; weight <= K; ++weight) {
			DP[idx][weight] = DP[idx - 1][weight];			
			if (weight - W >= 0)
				DP[idx][weight] = max(DP[idx][weight], DP[idx-1][weight - W] + V);
			answer = max(answer, DP[idx][weight]);
		}		
	}


	cout << answer;
}