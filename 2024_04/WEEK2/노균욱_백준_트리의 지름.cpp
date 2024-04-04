/*
트리의 지름

dfs인건 알겠는데 메모리 초과가 났다

10만 * 10만의 백터는 에바긴했다

이걸 해결하기 위해 구조체 백터 10만 짜리를 만드는게 더 낳아보임

모르겠음 그림을 그려가면서 구했는데 계속 감이 안잡혀서 이것에 대해서 maxNode를 찾는것을 힌트를 얻음
*/
#include <iostream>
#include <vector>

using namespace std;

int answer = 0,maxNode = 0;

struct Node{
    int point;
    int len;
};

void dfs(int start, const vector<Node> *v, vector<bool> &visited,int len){
    visited[start] = true;

    if(len > answer){
        answer = len;
        maxNode = start;
        //cout<<answer <<"   ";
    }

    for(int i = 0; i < v[start].size(); i++){
        int point = v[start][i].point;
        if(!visited[point]){
            dfs(v[start][i].point, v, visited, len + v[start][i].len);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);

    int n;

    cin >> n;
    vector<Node> v[100001];
    vector<bool>visited(n + 1, false);
    

    int start, end, len;
    for(int i = 0 ; i < n; i++){
        cin >> start;
        while(1){
            cin>> end;
            if(end == -1)
                break;
            cin >> len;
            v[start].push_back({end,len});
        }
    }

    dfs(1, v, visited, 0);

    fill(visited.begin(),visited.end(),false);
    answer = 0;
    dfs(maxNode, v, visited, 0);    

    cout << answer;
}