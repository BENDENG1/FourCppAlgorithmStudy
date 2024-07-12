#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll n, a, b;
vector<ll>v[100050];
ll dp[100050], inf = 1e12;
void dfs(ll x, ll par) {
	ll ret = inf;
	for (auto nxt : v[x]) {
		if (nxt == par)continue;
		dfs(nxt, x);
		ret = min(ret, dp[nxt]);
	}
	if (ret == inf)ret = 0;
	dp[x] = x - ret;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i < n; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1, 0);
	for (int i = 1; i <= n; i++) {
		if (dp[i] >= 0)cout << "1";
		else cout << "0";
		cout << '\n';
	}
}