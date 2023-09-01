#include <iostream>
#include <vector>

using namespace std;

// 게임 보드를 나타내는 2차원 벡터
vector<string> board;

// 같은 모양의 2x2 블록을 찾아 제거하는 함수
int removeBlocks(int m, int n) {
    int removedCount = 0;
    
    while (true) {
        bool found = false;
        vector<vector<bool>> toRemove(m, vector<bool>(n, false));

        // 같은 모양의 2x2 블록을 찾아 표시
        for (int i = 0; i < m - 1; i++) {
            for (int j = 0; j < n - 1; j++) {
                if (board[i][j] != ' ' && board[i][j] == board[i + 1][j] &&
                    board[i][j] == board[i][j + 1] && board[i][j] == board[i + 1][j + 1]) {
                    toRemove[i][j] = true;
                    toRemove[i + 1][j] = true;
                    toRemove[i][j + 1] = true;
                    toRemove[i + 1][j + 1] = true;
                    found = true;
                }
            }
        }

        // 제거된 블록 카운트 증가
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (toRemove[i][j]) {
                    board[i][j] = ' ';
                    removedCount++;
                }
            }
        }

        // 블록을 밑으로 내림
        for (int j = 0; j < n; j++) {
            for (int i = m - 1; i >= 0; i--) {
                if (board[i][j] == ' ') {
                    for (int k = i - 1; k >= 0; k--) {
                        if (board[k][j] != ' ') {
                            board[i][j] = board[k][j];
                            board[k][j] = ' ';
                            break;
                        }
                    }
                }
            }
        }

        // 같은 모양의 2x2 블록이 더 이상 없으면 종료
        if (!found) {
            break;
        }
    }
    
    return removedCount;
}

int solution(int m, int n, vector<string> inputBoard) {
    board = inputBoard;
    
    int answer = 0;
    answer = removeBlocks(m, n);
    
    return answer;
}