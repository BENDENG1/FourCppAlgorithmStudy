/*
가장 큰 정사각형 찾기

정사각형이 되는 알고리즘을 찾아야한다.

근데 전체를 하나씩 계속 찾는다는 것은 불가능 하지 않나? 브루트포스는 아닐거 같은데

하지만 1000 1000 이면 음.. 그냥 y,x주루룩 가면서 확인하면 될듯?

1. 0이 나오면 그 전 너비를 return
2. 끝에 y랑 x에 닿으면 return 끝?

근데 이렇게 하니 효율성에서 다 틀림

그럼 대각선을 기준으로 판단하는 것은 어떨까?

1 1 
1 1 이 있을 때 대각선 기준으로 

1 1
1   이니 

1 1 
1 2 로 수정를 한다.

최솟값 +1 을 하면서 dp 처럼 갱신을 하면 되지 않을까?
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;;

int getMin(vector<vector<int>>& board, int y,int x);

int solution(vector<vector<int>> board)
{
    int len = board[0][0];
    int y = board.size();
    
    for(int i = 1 ; i < board.size();i++){
        for(int j = 1; j < board[i].size(); j++){
            if(board[i][j] == 1){
                board[i][j] = getMin(board,i,j);
                len = max(len,board[i][j]);
            }
        }
    }

    return len * len;
}

int getMin(vector<vector<int>>& board, int y,int x){
    return 1 + min({board[y - 1][x], board[y][x-1], board[y-1][x-1]});
}

/*
#include <iostream>
#include<vector>

using namespace std;

int answer = 0;
int getArea(vector<vector<int>>& board, int y, int x);

int solution(vector<vector<int>> board)
{
    int yLen = board.size();
    
    for(int i = 0; i < yLen; i++){
        int xLen = board[i].size();
        for(int j = 0; j < xLen; j++){
            if(board[i][j] == 1){
                answer = answer > getArea(board,i,j) ? answer : getArea(board,i,j);
            }
        }
    }
    return answer;
}

int getArea(vector<vector<int>>& board, int y, int x){
    int len = 1;
    
    while(1){
        if(board.size() <= y + len  || board[y].size() <= x + len)
            return len * len;
        for(int i = y; i <= y + len; i++){
            for(int j = x; j <= x + len; j++){
                if(board[i][j] == 0){
                    return len * len;
                }
            }
        }
        len++;
    }
}
*/