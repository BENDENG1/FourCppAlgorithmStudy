#include <iostream>
#include <queue>
#include <deque>
using namespace std;

int main(){
    int board[101][101] = {0};
    int n, k, l;
    int ans = 0;
    int idx = 1; 
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {-1, 0, 1, 0};
    
    cin >> n >> k;
    for(int i = 0; i < k; i++){
        int row, col;
        cin >> row >> col;
        board[row][col] = 2;
    }
    
    cin >> l;
    queue<pair<int, char>> q;

    for(int i = 0; i < l; i++){
        int x;
        char c;
        
        cin >> x >> c;
        q.push({x, c});
    }
    
    board[1][1] = 1;
    deque<pair<int, int>> dq;
    dq.push_back({1, 1});
    
    while(1){
        ans++;
        int nx = dq.back().second + dx[idx];
        int ny = dq.back().first + dy[idx];
        if(nx <= 0 || nx > n || ny <= 0 || ny > n || board[ny][nx] == 1)
            break;
        
        if(board[ny][nx] != 2){
            board[dq.front().first][dq.front().second] = 0;
            dq.pop_front();
        }
        board[ny][nx] = 1;
        dq.push_back({ny, nx});
        
        if(ans == q.front().first){
            char ch = q.front().second;
            if(ch == 'D')
                idx = (idx + 1) % 4;
            else
                idx = (idx - 1 + 4) % 4;
            q.pop();
        }
    }
    
    cout << ans << '\n';
    
    return 0;
}