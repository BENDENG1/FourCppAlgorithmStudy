#include <iostream>
#include <vector>
#include <cmath>
#define ll long long
using namespace std;

ll Init(vector<ll>&tree, vector<ll>&arr, int node, int left, int right) {
	if (left == right) return tree[node] = arr[left];
	else if(left!=right){
		int mid((left + right) / 2);
		tree[node] = Init(tree, arr, node * 2, left, mid);
		tree[node] += Init(tree, arr, node * 2 + 1, mid + 1, right);		
		return tree[node];
	}	
}

void Update(vector<ll>& tree, ll diff, int node, int idx, int left, int right) {
	if (idx < left || right < idx) return;
	tree[node] += diff;

	if (left == right) return;
	int mid((left + right) / 2);
	Update(tree, diff, node * 2, idx, left, mid);
	Update(tree, diff, node * 2 + 1, idx, mid + 1, right);
}

ll Sum(vector<ll>& tree, int node, int start, int end, int left, int right) {
	if (end < left || start > right) return 0;
	else if (start <= left && right <= end) return tree[node];
	else {
		ll ret(0);
		int mid((left + right) / 2);
		ret = Sum(tree, node * 2, start, end, left, mid);
		ret += Sum(tree, node * 2 + 1, start, end, mid + 1, right);
		return ret;
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N(0), M(0), K(0);
	cin >> N >> M >> K;

	int tree_h = ceil(log2(N));
	int tree_size = (1 << (tree_h + 1));	
	vector<ll>tree(tree_size, 0);
	vector<ll>arr(N + 1, 0);

	for (int idx = 1; idx <= N; ++idx) cin >> arr[idx];

	Init(tree, arr, 1, 1, N);	
	
	for (int idx = 0; idx < M + K; ++idx) {
		ll cmd(0), num1(0), num2(0);
		cin >> cmd >> num1 >> num2;
		if (cmd == 1) {
			Update(tree, num2 - arr[num1], 1, num1, 1, N);
			arr[num1] = num2;
		}
		else if (cmd == 2) {
			cout << Sum(tree, 1, num1, num2, 1, N) << '\n';
		}
	}
}