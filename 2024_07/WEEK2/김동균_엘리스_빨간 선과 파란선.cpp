#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <algorithm>

using namespace std;

int main() {
  int N = 0;
  cin >> N;
  vector<int> a(N);
  for (int i = 0; i < N - 1; i++)
    cin >> a[i];
  map<vector<int>, int> dp;
  dp[vector<int>(N, 1)] = 0;
  deque<vector<int>> queue;
  queue.emplace_front(N, 1);
  while (queue.size()) {
    auto v = queue[0];
    queue.pop_front();
    for (int i = 0; i < v.size(); i++) {
      for (int j = i + 1; j < v.size(); j++) {
        vector<int> u;
        for (int k = 0; k < v.size(); k++) {
          if (k == i)
            u.push_back(v[i] + v[j]);
          else if (k == j)
            continue;
          else
            u.push_back(v[k]);
        }
        sort(u.begin(), u.end());
        if (dp.count(u) == 0) {
          queue.push_back(u);
          dp[u] = dp[v] + (1 - a[N - v.size()]) * v[i] * v[j];
        } else {
          dp[u] = min(dp[u], dp[v] + (1 - a[N - v.size()]) * v[i] * v[j]);
        }
      }
    }
  }
  cout << dp[{N}] << endl;
}

//7월 15일자