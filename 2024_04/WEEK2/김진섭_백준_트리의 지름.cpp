/*
트리의 지름을 구하는 공식을 이용함.
임의의 점에서 최장 거리 정점을 구하고, 최장 거리 정점에서 최장 거리를 구한다.
구한 최장 거리가 트리의 지름이 된다.
*/

#include <iostream>
#include <algorithm>
#include <vector>
#define pii pair<int, int>
using namespace std;

void FindLongestVertex(int node, int dist, vector<int>& vertex, const vector<vector<pii>>& tree, vector<bool>& visited) {
	vertex[node] = dist;
	for (int idx = 0; idx < tree[node].size(); ++idx) {
		int next_node = tree[node][idx].first;
		int next_dist = tree[node][idx].second;
		if (visited[next_node] == true) continue;
		visited[next_node] = true;
		FindLongestVertex(next_node, dist + next_dist, vertex, tree, visited);
	}
}

int main() {
	int V(0);
	cin >> V;
	vector<vector<pii>>tree(V + 1, vector<pii>(0, { 0,0 }));

	int parent(0), child(0), dist(0);
	for (int idx = 0; idx < V; ++idx) {
		cin >> parent;
		while (1) {
			cin >> child;
			if (child == -1) break;
			cin >> dist;
			tree[parent].push_back({ child, dist });
		}
	}

	vector<int>vertex_dist(V + 1, 0);
	vector<bool>visited(V + 1, false);

	visited[1] = true;
	FindLongestVertex(1, 0, vertex_dist, tree, visited);

	int longest_node(0), longest_dist(0), answer(0);
	dist = 0;
	for (int node = 2; node <= V; ++node) {
		if (longest_dist < vertex_dist[node]) {
			longest_dist = vertex_dist[node];
			longest_node = node;
		}
	}

	fill(vertex_dist.begin(), vertex_dist.end(), 0);
	fill(visited.begin(), visited.end(), false);

	longest_dist = 0;
	visited[longest_node] = true;
	FindLongestVertex(longest_node, 0, vertex_dist, tree, visited);
	for (int node = 1; node <= V; ++node) {
		longest_dist = max(longest_dist, vertex_dist[node]);
	}

	answer = longest_dist;
	cout << answer;
}