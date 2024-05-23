#include <iostream>
#include <vector>
using namespace std;
//세그먼트 트리 참고했습니당
vector<intptr_t> arr;
vector<intptr_t> tree;

intptr_t initialize(int start, int end, int index) {
    if (start == end) {
        tree[index] = arr[start];
        return tree[index];
    }
    int mid = (start + end) / 2;
    tree[index] = init(start, mid, index * 2) + init(mid + 1, end, index * 2 + 1);
    return tree[index];
}

intptr_t interval_sum(int start, int end, int index, int left, int right) {
    if (left > end || right < start) return 0;
    if (left <= start && right >= end) return tree[index];
    int mid = (start + end) / 2;
    return interval_sum(start, mid, index * 2, left, right) + interval_sum(mid + 1, end, index * 2 + 1, left, right);
}

void update(int start, int end, int index, int what, intptr_t value) {
    if (what < start || what > end) return;
    tree[index] += value;
    if (start != end) {
        int mid = (start + end) / 2;
        update(start, mid, index * 2, what, value);
        update(mid + 1, end, index * 2 + 1, what, value);
    }
}

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    arr.resize(N + 1);
    tree.resize(4 * N);

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    initialize(1, N, 1);

    for (int i = 0; i < M + K; i++) {
        int a, b;
        intptr_t c;
        cin >> a >> b >> c;
        if (a == 1) {
            intptr_t diff = c - arr[b];
            arr[b] = c;
            update(1, N, 1, b, diff);
        } else if (a == 2) {
            cout << interval_sum(1, N, 1, b, c) << '\n';
        }
    }

    return 0;
}