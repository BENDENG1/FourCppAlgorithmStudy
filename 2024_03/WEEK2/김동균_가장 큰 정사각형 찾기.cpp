#include <iostream>
#include <vector>
using namespace std;

int dp(vector<vector<int>> board) {
    int maxSide = board[0][0];
    int rows = board.size();
    int cols = board[0].size();

    // 첫 행과 첫 열은 변의 길이가 1일 때만 가능한 정사각형이므로, 그대로 유지
    for (int i = 1; i < rows; i++) {
        for (int j = 1; j < cols; j++) {
            if (board[i][j] == 1) {
                // 현재 위치에서 만들 수 있는 정사각형의 변의 최대 길이
                int side = min(board[i - 1][j - 1], min(board[i - 1][j], board[i][j - 1])) + 1;
                //왼쪽아래,왼쪽,아래쪽을 비교 했을때 가장 작은값
                board[i][j] = side; // 변의 길이를 해당 위치에 저장
                maxSide = max(maxSide, side); // 최대 변의 길이 갱신
            }
        }
    }
    
    return maxSide * maxSide; // 최대 변의 길이의 제곱이 최대 정사각형의 넓이
}

int solution(vector<vector<int>> board) {
    int answer = dp(board);
    return answer;
}
