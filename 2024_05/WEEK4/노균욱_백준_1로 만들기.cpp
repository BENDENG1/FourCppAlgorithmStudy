/*


*/
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;
vector<int> dp;
int min(int a, int b) { return a > b ? b : a; }

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

	int x;
	cin >> x;
	
    dp.resize(x + 1,0);
	dp.push_back(0);
    dp.push_back(0);

	for (int i = 2; i <= x; i++) {
		dp[i] = dp[i - 1] + 1;
		if (i % 2 == 0)
			dp[i] = min(dp[i], dp[i / 2] + 1);
		if (i % 3 == 0)
			dp[i] = min(dp[i], dp[i / 3] + 1);
	}
	cout << dp[x];
}