/*
거리두기 확인하기

5*5 맨허튼 거리 2 이하로 앉지 x / but 파티션 막혀있는경우 o

둘의 직선 거리가 1이하 일 때 -> 파티션 없으면 무조건 return 0
둘이 대각선일 때 -> 사각형의 둘다 파티션이 없으면 return 0

근데 그냥 5*5인데 시간복잡도 생각할 필요가 있나?
*/
#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool check(const vector<string>& places,int y, int x);

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    for(int i =  0 ; i < places.size(); i++){
        bool flag = true;
        for(int j =  0; j < places[i].size(); j ++){
            for(int k = 0 ; k < places[i][j].length(); k++){
                if(places[i][j][k] == 'P'){
                    if(check(places[i], j, k) == false){
                        flag = false;
                        break;
                    }
                }
            }
            if(flag == false){
                break;
            }
        }
        if(flag)
            answer.push_back(1);
        else
            answer.push_back(0);
    }
    return answer;
}

bool check(const vector<string>& place,int y, int x){
    for(int i = -2; i <= 2;i++){
        for(int j = -2; j <= 2; j++){
            if(0 <= y + i && y + i <= 4 && 0 <= x + j && x + j <= 4){ // 5* 5 범위 내에 드는거
                if(abs(i) + abs(j) != 0 && abs(i) + abs(j) <= 2){ //자기 위치가 아닌 모든 곳의 거리 계산
                    if(place[y + i][x + j] == 'P'){ // 만약 플레이어라면
                        if(abs(i) + abs(j) == 1){
                            return false;
                        }
                        else if(abs(i) == 1 && abs(j) == 1){
                            if(!(place[y + i][x] == 'X' && place[y][x + j] == 'X'))
                                return false;
                        }
                        else{
                            //여기는 i = -2,2 j = 0 혹은 i = 0,j= -2,2 인 경우임
                            if(i == -2){
                                if(!(place[y + i + 1][x] == 'X'))
                                    return false;
                            }
                            else if(i == 2){
                                if(!(place[y + i - 1][x] == 'X'))
                                    return false;
                            }
                            else if(j == -2){
                                if(!(place[y][x + j + 1] == 'X'))
                                    return false;
                            }
                            else if(j == 2){
                                if(!(place[y][x + j - 1] == 'X'))
                                    return false;
                            }
                        }
                    }
                }
            }
        }
    }
    return true;
}
