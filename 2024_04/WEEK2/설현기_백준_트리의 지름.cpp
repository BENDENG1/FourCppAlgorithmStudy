#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

struct node{
    int vertex;
    int dist;
};

vector<node> v[100001];
bool visited[100001];
int maxnode, maxdist;

void dfs(int cur, int dist){
    if(visited[cur]){
        return;
    }
    visited[cur] = true;
    
    if(maxdist < dist){
        maxdist = dist;
        maxnode = cur;
    }
    
    for(int i = 0; i < v[cur].size(); i++){
        int nextvertex = v[cur][i].vertex;
        int nextdist = v[cur][i].dist;
        dfs(nextvertex, dist + nextdist);
    }
}

int main(){
    int n, cur = 0, next = 0, dis = 0;
    
    cin >> n;
    
    for(int i = 0; i < n + 1; i++){
        cin >> cur;
        while(true){
            cin >> next;
            if(next == -1)
                break;
            cin >> dis;
            v[cur].push_back({next, dis});
            v[next].push_back({cur, dis});
        }
    }
    
    dfs(1, 0);
    memset(visited, 0, sizeof(visited));
    maxdist = 0;
    dfs(maxnode, 0);
    
    cout << maxdist << "\n";
    
    return 0;
}