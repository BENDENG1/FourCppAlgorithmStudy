/*
뱀

n * n 이고 처음에는 오른쪽을 향하고 길이는 1
*/
#include <iostream>
#include <vector>
#include <queue>
#include <deque>

using namespace std;

struct Snake{
    int y;
    int x;
};

struct Play{
    int time;
    char dir;
};

int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};

int setDirection(int dir, char c){
    if(c == 'L'){
        if(dir == 0) return 3;
        else if(dir == 1) return 2;
        else if(dir == 2) return 0;
        else return 1;
    }else{
        if(dir == 0) return 2;
        else if(dir == 1) return 3;
        else if(dir == 2) return 1;
        else return 0;
    }
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL); 

    int n, k, x, y, l, time, ans = 1, dir = 0;
    char c;
    bool flag = false;

    cin >> n >> k;
    vector<vector<int>> v(n , vector<int> (n, 0));
    deque<Snake> snakeDeque;
    queue<Play> playQ;

    snakeDeque.push_back({0,0});

    for(int i = 0; i < k; i++){
        cin >> y >> x;
        v[y - 1][x - 1] = 1;
    }
    cin >> l;
    y = x = 0;

    for(int i = 0; i < l; i++){
        cin >> time >> c;
        playQ.push({time, c});
    }

    while(true){
        int ny = snakeDeque.front().y + dy[dir];
        int nx = snakeDeque.front().x + dx[dir];

        if(0 > ny || ny >= n  || 0 > nx || nx >= n){
            flag = true;
        }
        for(int i = 0; i < snakeDeque.size();i++){
            if(ny == snakeDeque[i].y && nx == snakeDeque[i].x){
                flag = true;
            }
        }
        if(flag) break;

        if(snakeDeque.size() > 1){
            if(v[ny][nx] == 0){
                snakeDeque.pop_back();
            }else{
                v[ny][nx] = 0;
            }
            snakeDeque.push_front({ny, nx});
        }else{
            if(v[ny][nx] == 1){
                v[ny][nx] = 0;
            }else{
                snakeDeque.pop_back();
            }
            snakeDeque.push_front({ny,nx});
        }

        if(!playQ.empty() && playQ.front().time == ans){
            Play play = playQ.front();
            dir = setDirection(dir, play.dir);
            playQ.pop();
        }
        ans++;
    }

    cout << ans;
    return 0;
}