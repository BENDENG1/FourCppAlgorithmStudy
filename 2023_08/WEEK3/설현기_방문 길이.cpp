#include <string>
using namespace std;
int direction(char c){
    if(c == 'U'){
            return 0;
    }
    else if(c == 'D'){
            return 1;
    }
    else if(c == 'R'){
            return 2;
    }
    else{
            return 3;
    }
}
int solution(string dirs) {
    int answer = 0;
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    int x = 5;
    int y = 5;
    int nx, ny;
    int visited[11][11][11][11] = {0};
    
    for(int i = 0; i < dirs.length(); i++){
        int dir = direction(dirs[i]);
        nx = x + dx[dir];
        ny = y + dy[dir];
        if(nx < 0 || nx > 10 || ny < 0 || ny > 10){
            continue;
        }
        else{
            if(visited[x][y][nx][ny] == 0){
                answer++;
                visited[x][y][nx][ny] = 1;
                visited[nx][ny][x][y] = 1;
            }
        }
        x = nx;
        y = ny;
    }
    return answer;
}