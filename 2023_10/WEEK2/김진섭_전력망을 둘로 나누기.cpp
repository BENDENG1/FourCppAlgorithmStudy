//문제풀이: https://githubseob.tistory.com/354

#include <string>
#include <vector>
using namespace std;
vector<vector<int>>tree;
vector<bool>visited;
int N, answer;

int DFS(int node) {
    int node_cnt(1);
    for (int idx = 0; idx < tree[node].size(); ++idx) {
        int next_node = tree[node][idx];
        if (visited[next_node] == true) continue;
        else {
            visited[next_node] = true;
            node_cnt += DFS(next_node);
        }
    }
    answer = min(answer, abs(N - node_cnt - node_cnt));
    return node_cnt;
}

int solution(int n, vector<vector<int>> wires) {
    answer = N = n;

    tree = vector<vector<int>>(N + 1);
    visited = vector<bool>(N + 1, false);

    for (int idx = 0; idx < wires.size(); ++idx) {
        int node1 = wires[idx][0];
        int node2 = wires[idx][1];
        tree[node1].push_back(node2);
        tree[node2].push_back(node1);
    }

    DFS(1);
    return answer;
}