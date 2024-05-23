#include <iostream>
#include <vector>
#include <limits>
using namespace std;

vector<int> arr;
vector<pair<int, int>> tree;

void initialize(int node, int start, int end) {
    if (start == end) {
        tree[node] = make_pair(arr[start], arr[start]);
    } else {
        int mid = (start + end) / 2;
        initialize(node * 2, start, mid);
        initialize(node * 2 + 1, mid + 1, end);
        tree[node].first = min(tree[node * 2].first, tree[node * 2 + 1].first);
        tree[node].second = max(tree[node * 2].second, tree[node * 2 + 1].second);
    }
}

pair<int, int> interval_min_max(int node, int start, int end, int left, int right) {
    if (left > end || right < start) {
        return make_pair(numeric_limits<int>::max(), numeric_limits<int>::min());
    }
    if (left <= start && right >= end) {
        return tree[node];
    }
    int mid = (start + end) / 2;
    pair<int, int> left_result = interval_min_max(node * 2, start, mid, left, right);
    pair<int, int> right_result = interval_min_max(node * 2 + 1, mid + 1, end, left, right);
    return make_pair(min(left_result.first, right_result.first), max(left_result.second, right_result.second));
}

int main() {
    int N, M;
    cin >> N >> M;

    arr.resize(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    tree.resize(4 * N);
    initialize(1, 1, N);

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        pair<int, int> result = interval_min_max(1, 1, N, a, b);
        cout << result.first << " " << result.second << endl;
    }

    return 0;
}
//시간 초과로 다시 풀예정