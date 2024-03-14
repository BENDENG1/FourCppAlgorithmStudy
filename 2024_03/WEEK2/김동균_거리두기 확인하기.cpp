#include <string>
#include <vector>
using namespace std;

// 상, 하, 좌, 우, 대각선 방향 정의
int dx[] = {1, -1, 0, 0, 1, -1, 1, -1};
int dy[] = {0, 0, 1, -1, 1, 1, -1, -1};

bool isInRange(int x, int y, int size) {
    return x >= 0 && x < size && y >= 0 && y < size;
}

bool ischeck(vector<string> board) {
    int size = board.size();
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < board[i].size(); j++) {
            if (board[i][j] == 'P') {
                // 8가지 방향(상, 하, 좌, 우, 대각선) 탐색
                for (int direction = 0; direction < 8; direction++) {
                    int nx = i + dx[direction];
                    int ny = j + dy[direction];
                    // 범위 체크
                    if (!isInRange(nx, ny, size)) continue;
                    // 주변에 P가 있는 경우
                    if (board[nx][ny] == 'P') {
                        // 직선 방향인 경우
                        if (direction < 4) {
                            return false;
                        }
                        // 대각선 방향인 경우, 사이에 X가 있어야 함
                        else {
                            if (!(board[i][ny] == 'X' && board[nx][j] == 'X')) {
                                return false;
                            }
                        }
                    } 
                    // 직접적으로 인접한 경우 'O' 확인 로직은 기존과 동일
                    else if(board[nx][ny] == 'O' && direction < 4){
                        int nnx = nx + dx[direction];
                        int nny = ny + dy[direction];
                        if (!isInRange(nnx, nny, size)) continue;
                        if (board[nnx][nny] == 'P') return false;
                    }
                }
            }
        }
    }
    return true; // 모든 조건을 만족하는 경우
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for (auto lobby : places) {
        if (ischeck(lobby))
            answer.push_back(1);
        else
            answer.push_back(0);
    }
    return answer;
}