#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> board)
{
    int answer = board[0][0];
    int n = board.size();
    int m = board[0].size();
    
    for(int i = 1; i < n; i++)
    {
        for(int j = 1; j < m; j++)
        {
            if(board[i][j] == 1){
                // 주위 원소의 최솟값 + 1 (주위에 0이 있다면 1로 유지)
                board[i][j] = 1 + min({board[i - 1][j - 1], board[i - 1][j], board[i][j - 1]}); 
                answer = max(answer, board[i][j]);
            }
        }
    }

    return answer * answer;
}