#include <string>
#include <vector>
#include <queue>
#include <cstdlib>

using namespace std;

vector<int> tree[101];
int answer = 0;
int cnt;

void bfs(int node1, int node2){
    queue<int> q;
    q.push(node1);
    vector<bool> visited(101,false);
    visited[node1] = true;
    visited[node2] = true;
    
    while(!q.empty()){
        int node = q.front();
        q.pop();
        
        for(int i =0 ; i < tree[node].size() ; i++){
            int point = tree[node][i];
            if(!visited[point]){
                cnt++;
                q.push(point);
                visited[point] = true;
            }
        }
    }
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 101;
    
    for(int i = 0 ; i < wires.size();i++){
        tree[wires[i][0]].push_back(wires[i][1]);
        tree[wires[i][1]].push_back(wires[i][0]);
    }
    
    for(auto wire : wires){
        cnt = 1;
        int node1 = wire[0];
        int node2 = wire[1];
        
        bfs(node1,node2);
        answer = min(answer, abs(2 * cnt - n));
    }
    
    return answer;
}