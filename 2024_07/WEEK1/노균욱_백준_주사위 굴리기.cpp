/*
주사위 굴리기

0인경우 바닥에 복사, 아닌 경우 수가 바닥면으로 복사되며 칸 0


*/
#include <iostream>

using namespace std;

int dy[5] = {0, 0, 0, -1, 1};
int dx[5] = {0, 1, -1, 0, 0};
int board[21][21] = {0,};
int dice[6] = {0,}; //맨위, 정면, 아래, 뒷쪽,왼쪽, 오른쪽

void move(int dir){
    if(dir == 1){
        int tmp = dice[5];
        dice[5] = dice[0];
        dice[0] = dice[4];
        dice[4] = dice[2];
        dice[2] = tmp;
    }else if(dir == 2){
        int tmp = dice[5];
        dice[5] = dice[2];
        dice[2] = dice[4];
        dice[4] = dice[0];
        dice[0] = tmp;
    }else if(dir == 3){
        int tmp = dice[0];
        dice[0] = dice[1];
        dice[1] = dice[2];
        dice[2] = dice[3];
        dice[3] = tmp;

    }else{
        int tmp = dice[0];
        dice[0] = dice[3];
        dice[3] = dice[2];
        dice[2] = dice[1];
        dice[1] = tmp;
    }
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);

    int n, m, r, c, k, dir;

    cin >> n >> m >> r >> c >> k;

    for(int i = 0 ; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> board[i][j];
        }
    }

    for(int i = 0 ; i < k; i++){
        cin >> dir;
        int ny = r + dy[dir];
        int nx = c + dx[dir];
        if(0 <= ny && ny < n  && 0 <= nx && nx < m){
            r = ny;
            c = nx;
            move(dir);
            if(board[ny][nx] == 0){
                board[ny][nx] = dice[2];
            }else{
                dice[2] = board[ny][nx];
                board[ny][nx] = 0;
            }
            cout << dice[0] << "\n";
        }
    }
}