#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;

bool visited[51];
int arr[51][51];
int dist[51];

void dfs(int start,int count,int k,int n){
    for(int i = 1; i <= n;i++){
        if(start != i && arr[start][i] != 0 && !visited[i] && count + arr[start][i] <= k){
            visited[i] = true;
            dist[i] = min(dist[i] , count + arr[start][i]);
            dfs(i,count + arr[start][i],k,n);
            visited[i] = false;
        }
    }
}

int solution(int N, vector<vector<int>> road, int K) {
    int answer = 0;
    
    memset(arr,10000,sizeof(arr));
    memset(visited,false,sizeof(visited));
    for(int i = 2; i <= N;i++){
        dist[i] = 500000;
    }
    for(int i = 0 ;i < road.size();i++){
        if(arr[road[i][0]][road[i][1]] > road[i][2]){
            arr[road[i][0]][road[i][1]] = road[i][2];
            arr[road[i][1]][road[i][0]] = road[i][2];
        }
    }
    dfs(1,0,K,N);
    
    for(int i = 1 ; i <= N;i++){
        if(dist[i] <= K){
            answer++;
        }
    }

    return answer;
}
