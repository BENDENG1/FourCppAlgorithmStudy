#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#define ll long long
#define MAX 1e9
using namespace std;

int min_Init(vector<int>& tree, vector<int>& arr, int left, int right, int node) {
	if (left == right) return tree[node] = arr[left];
	else if(left!=right){
		int mid((left + right) / 2);
		return tree[node] = min(min_Init(tree, arr, left, mid, node * 2),
			min_Init(tree, arr, mid + 1, right, node * 2 + 1));
	}
}

int max_Init(vector<int>& tree, vector<int>& arr, int left, int right, int node) {
	if (left == right) return tree[node] = arr[left];
	else if (left != right) {
		int mid((left + right) / 2);
		return tree[node] = max(max_Init(tree, arr, left, mid, node * 2),
			max_Init(tree, arr, mid + 1, right, node * 2 + 1));
	}
}

int min_find(vector<int>& tree, int start, int end, int left, int right, int node) {
	if (start <= left && right <= end) return tree[node];
	else if (right < start || end < left) return MAX;
	int ret(0), mid((left+right)/2);
	ret = min_find(tree, start, end, left, mid, node * 2);
	ret = min(ret, min_find(tree, start, end, mid + 1, right, node * 2 + 1));
	return ret;
}

int max_find(vector<int>& tree, int start, int end, int left, int right, int node) {
	if (start <= left && right <= end) return tree[node];
	else if (right < start || end < left) return 0;
	int ret(0), mid((left + right) / 2);
	ret = max_find(tree, start, end, left, mid, node * 2);
	ret = max(ret, max_find(tree, start, end, mid + 1, right, node * 2 + 1));
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N(0), M(0);
	cin >> N >> M;	

	int tree_h = ceil(log2(N));
	int tree_size = (1 << (tree_h + 1));
	vector<int>min_Tree(tree_size, MAX);
	vector<int>max_Tree(tree_size, 0);

	vector<int>arr(N + 1, 0);

	for (int idx = 1; idx <= N; ++idx) cin >> arr[idx];

	min_Init(min_Tree, arr, 1, N, 1);
	max_Init(max_Tree, arr, 1, N, 1);

	int start(0), end(0);
	for (int idx = 0; idx < M; ++idx) {
		cin >> start >> end;
		cout << min_find(min_Tree, start, end, 1, N, 1) << ' ';
		cout << max_find(max_Tree, start, end, 1, N, 1) << '\n';
	}
}