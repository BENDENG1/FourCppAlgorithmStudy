//문제풀이: https://githubseob.tistory.com/361

#include <queue>
#include <vector>
#define pii pair<int, int>
#define INF 1e5
using namespace std;

int Dijkstra(int N, int K, vector<vector<pii>>roads) {
    priority_queue<pii>pq;
    pq.push({ 0,1 });
    vector<int>dists(N + 1, INF);

    while (!pq.empty()) {
        int dist = -pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for (int idx = 0; idx < roads[node].size(); ++idx) {
            int next_node = roads[node][idx].first;
            int next_dist = roads[node][idx].second;
            if (dists[next_node] > dist + next_dist) {
                dists[next_node] = dist + next_dist;
                pq.push({ -dists[next_node], next_node });
            }
        }
    }
    int ret(0);
    for (int node = 2; node <= N; ++node) {
        if (dists[node] <= K) ++ret;
    }

    return ret;
}

int solution(int N, vector<vector<int>> road, int K) {
    int answer(0);
    vector<vector<pii>>roads(N + 1);
    for (int idx = 0; idx < road.size(); ++idx) {
        int node1 = road[idx][0];
        int node2 = road[idx][1];
        int dist = road[idx][2];

        roads[node1].push_back({ node2, dist });
        roads[node2].push_back({ node1, dist });
    }

    answer = Dijkstra(N, K, roads);

    return answer;
}