/*
실습용 로봇

좌우 회전 전진 후진

*/
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

vector<int> solution(string command) {
    vector<int> answer;
    
    int dir = 0;
    int y = 0, x = 0;
    
    for(int i = 0; i < command.length(); i++){
        if(command[i] == 'R'){
            if(dir < 3)
                dir += 1;
            else
                dir = 0;
        }else if(command[i] == 'L'){
            if(dir > 0)
                dir -= 1;
            else
                dir = 3;
        }else if (command[i] == 'G'){
            x += dx[dir];
            y += dy[dir];
        }else{
            x -= dx[dir];
            y -= dy[dir];
        }
    }
    answer.push_back(x);
    answer.push_back(y);
    return answer;
}