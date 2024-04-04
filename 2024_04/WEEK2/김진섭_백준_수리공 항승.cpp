//문제풀이: https://githubseob.tistory.com/382

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N(0), L(0);
	cin >> N >> L;

	--L;

	vector<int>location(N, 0);
	for (int idx = 0; idx < N; ++idx) {
		cin >> location[idx];
	}
	sort(location.begin(), location.end());

	int prev(-1000), answer(0);
	
	for (int idx = 0; idx < N; ++idx) {
		if (location[idx] > prev + L) {			
			++answer;
			prev = location[idx];
		}
	}
	cout << answer;
}