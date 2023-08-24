/*
위아오왼 UDRL으로 한칸씩

캐릭터가 처음 걸어본 길의 길이 
결국 겹치는 길이를 빼고 얼만큼 걸었는지에 대해서 처리를 하는것이다.
또한 판의 범위를 넘어가게 되면 명령어를 무시하는것
  Y  X
U -1 0
D 1  0
R 0 1
L 0 -1
*/
#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string dirs) {
    int answer = 0;
    int y = 5; int x = 5;
    int ny = 0; int nx = 0;
    //위 아래 오른쪽 왼쪽
    int dy[4] = {-1,1,0,0};
    int dx[4] = {0,0,1,-1};
    bool visited[11][11][4]= {false,}; //위,아래,오른쪽,아래 기준으로 오는걸 삼음
    
    for(int i = 0; i < dirs.length();i++){
        int direction = 0;
        int opposite = 0;
        
        if(dirs[i] == 'U'){
            ny = y + dy[0]; nx = x + dx[0]; direction = 0; opposite = 1;
        }else if(dirs[i] == 'D'){
            ny = y + dy[1]; nx = x + dx[1]; direction = 1; opposite = 0;
        }else if(dirs[i] == 'R'){
            ny = y + dy[2]; nx = x + dx[2]; direction = 2; opposite = 3;
        }else if(dirs[i] == 'L'){
            ny = y + dy[3]; nx = x + dx[3]; direction = 3; opposite = 2;
        }
        
        if(0 <= ny && ny <= 10 && 0 <= nx && nx <= 10){
            if(visited[ny][nx][direction] == false && visited[y][x][opposite] == false){
                answer++;
                visited[ny][nx][direction] = true;
            }
            y = ny;
            x = nx;
        }
        
    }
    return answer;
}