#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

long long solve(const int &N, const int &K, vector<pair<int, int>>& jewelry, vector<int>& bags) {
    priority_queue<int, vector<int>, less<int>> pq;
    sort(jewelry.begin(), jewelry.end());
    sort(bags.begin(), bags.end());
    int idx = 0;
    long long sum = 0;

    for (int i = 0; i < K; i++) {
        while (idx < N && bags[i] >= jewelry[idx].first) {
            pq.push(jewelry[idx].second);
            idx++;
        }
        if (!pq.empty()) {
            sum += pq.top();
            pq.pop();
        }
    }
    return sum;
}

int main() {
    int N, K; // 보석 수, 가방 수
    cin >> N >> K;

    vector<pair<int, int>> jewelry(N); // 보석의 무게와 가격을 저장할 벡터
    for (int i = 0; i < N; ++i) {
        cin >> jewelry[i].first >> jewelry[i].second;
    }

    vector<int> bags(K); // 가방의 용량을 저장할 벡터
    for (int i = 0; i < K; ++i) {
        cin >> bags[i];
    }

    cout << solve(N, K, jewelry, bags);
    return 0;
}
