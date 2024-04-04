//문제풀이: https://githubseob.tistory.com/379

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N(0), H(0);
	cin >> N >> H;

	vector<int>odd(H + 1, 0);
	vector<int>even(H + 1, 0);

	int height(0);
	for (int idx = 1; idx <= N; ++idx) {
		cin >> height;
		if (idx % 2 == 1) ++odd[height];
		else if (idx % 2 == 0) ++even[height];
	}
	for (height = H - 1; height >= 1; --height) {
		odd[height] += odd[height + 1];
		even[height] += even[height + 1];		
	}

	vector<int>obstacle(H + 1, 0);
	for (height = 1; height <= H; ++height) {
		obstacle[height] = odd[height] + even[H - height + 1];		
	}

	sort(obstacle.begin(), obstacle.end());
	int right = upper_bound(obstacle.begin() + 1, obstacle.end(), obstacle[1]) - obstacle.begin();
	cout << obstacle[1] << " " << right - 1;
}