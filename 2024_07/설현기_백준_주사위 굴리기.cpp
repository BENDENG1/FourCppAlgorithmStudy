#include <iostream>
#include <vector>
using namespace std;

int dice[7] = {0};

void rollDice(int d){
    int d1, d2, d3, d4, d5, d6;
    d1 = dice[1];
    d2 = dice[2];
    d3 = dice[3];
    d4 = dice[4];
    d5 = dice[5];
    d6 = dice[6];
    
    if(d == 1){
        dice[1] = d4;
        dice[4] = d3;
        dice[3] = d2;
        dice[2] = d1;
    }
    else if(d == 2){
        dice[1] = d2;
        dice[2] = d3;
        dice[3] = d4;
        dice[4] = d1;
    }
    else if(d == 3){
        dice[1] = d5;
        dice[5] = d3;
        dice[3] = d6;
        dice[6] = d1;
    }
    else if(d == 4){
        dice[1] = d6;
        dice[6] = d3;
        dice[3] = d5;
        dice[5] = d1;
    }
}

int main(){
    int map[21][21] = {0};
    int dx[4] = {0, 0, -1, 1}; 
    int dy[4] = {1, -1, 0, 0}; 
    int n, m, x, y, k;
    vector<int> order;
    
    cin >> n >> m >> x >> y >> k;
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> map[i][j];
        }
    }
    
    for(int i = 0; i < k; i++){
        int a;
        cin >> a;
        order.push_back(a);
    }
    
    x++;
    y++;
    
    for(int i = 0; i < order.size(); i++){
        int nx = x + dx[order[i] - 1];
        int ny = y + dy[order[i] - 1];
        
        if(nx < 1 || nx > n || ny < 1 || ny > m)
            continue;
        rollDice(order[i]);
        if(map[nx][ny] == 0)
            map[nx][ny] = dice[3];
        else{
            dice[3] = map[nx][ny];
            map[nx][ny] = 0;
        }
            
        cout << dice[1] << "\n";
            
        x = nx;
        y = ny;
    }
    return 0;
}
