//문제풀이: https://githubseob.tistory.com/206

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define ll long long
#define pii pair<int, int>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N(0), K(0);
	cin >> N >> K;

	priority_queue<int>pq;
	vector<pii>jewel(N, { 0,0 });
	vector<int>bag(K, 0);

	for (int idx = 0; idx < N; ++idx) {		
		cin >>jewel[idx].first >> jewel[idx].second;
	}
	for (int idx = 0; idx < K; ++idx) {
		cin >> bag[idx];
	}

	sort(bag.begin(), bag.end());
	sort(jewel.begin(), jewel.end());

	int jewel_idx(0);
	ll answer(0);
	
	for (int idx = 0; idx < K; ++idx) {
		for (jewel_idx; jewel_idx < N; ++jewel_idx) {
			if (bag[idx] >= jewel[jewel_idx].first) {
				pq.push(jewel[jewel_idx].second);
			}
			else break;
		}
		if (pq.empty()) continue;
		answer += pq.top();
		pq.pop();
	}
	

	cout << answer;
}