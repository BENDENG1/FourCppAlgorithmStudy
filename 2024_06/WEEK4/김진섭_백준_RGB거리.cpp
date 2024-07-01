#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N(0);
	cin >> N;
	
	vector<vector<int>>house(N, vector<int>(3, 0));

	for (int idx = 0; idx < N; ++idx) {
		cin >> house[idx][0] >> house[idx][1] >> house[idx][2];
	}	

	for (int idx = 1; idx < N; ++idx) {
		house[idx][0] = house[idx][0] + min(house[idx - 1][1], house[idx - 1][2]);
		house[idx][1] = house[idx][1] + min(house[idx - 1][0], house[idx - 1][2]);
		house[idx][2] = house[idx][2] + min(house[idx - 1][0], house[idx - 1][1]);		
	}
	cout << *min_element(house[N-1].begin(), house[N-1].end());
}