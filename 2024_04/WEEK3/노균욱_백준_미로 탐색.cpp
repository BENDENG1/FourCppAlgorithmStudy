/*
미로 탐색

*/
#include <iostream>
#include <queue>

using namespace std;

struct point{
    int y;
    int x;
    int cnt;
};

int n, m;
int arr[101][101] = {0,};
bool visited[101][101] = {false, };
int dy[4] = {0,0,1,-1};
int dx[4] = {1,-1,0,0};

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);


    queue<point> q;
    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        string s;
        cin >> s;
        for(int j = 1; j <= m; j++){
            arr[i][j] = (int)(s[j - 1] - '0');
        }
    }

    q.push({1, 1, 1});
    while(!q.empty()){
        point p = q.front();

        if(p.y == n && p.x == m){
            cout << p.cnt;
            break;
        }
        q.pop();
        
        for(int i = 0 ; i < 4; i++){
            int ny = p.y + dy[i];
            int nx = p.x + dx[i];

            if(1 <= ny && ny <= n && 1 <= nx && nx <= m && !visited[ny][nx] && arr[ny][nx] == 1){
                q.push({ny, nx, p.cnt + 1});
                visited[ny][nx] = true;
            }
        }
    }
}