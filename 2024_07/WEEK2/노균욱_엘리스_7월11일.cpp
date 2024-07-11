#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

#define INT_MAX 2147483647

vector<vector<int>> adjList;
vector<int> dp;
vector<bool> visited;

int main() {
    ios_base::sync_with_stdio(0),cin.tie(NULL),cout.tie(NULL);

    int n;
    cin >> n;
    adjList.resize(n + 1);
    dp.resize(n + 1);
    visited.resize(n + 1, false);

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    stack<int> stack;
    queue<int> queue;
    queue.push(1);
    visited[1] = true;

    while (!queue.empty()) {
        int node = queue.front();
        queue.pop();
        stack.push(node);
        for (int child : adjList[node]) {
            if (!visited[child]) {
                visited[child] = true;
                queue.push(child);
            }
        }
    }

    fill(visited.begin(), visited.end(), false);

    while (!stack.empty()) {
        int node = stack.top();
        stack.pop();
        visited[node] = true;
        bool isLeaf = true;

        int minChildValue = INT_MAX;
        for (int child : adjList[node]) {
            if (visited[child]) {
                isLeaf = false;
                minChildValue = min(minChildValue, dp[child]);
            }
        }

        if (isLeaf) {
            dp[node] = node;
        } else {
            dp[node] = node - minChildValue;
        }
    }

    for (int i = 1; i <= n; ++i) {
        if (dp[i] >= 0) {
            cout << 1 << "\n";
        } else {
            cout << 0 << "\n"; 
        }
    }

    return 0;
}