//문제풀이: https://githubseob.tistory.com/337

#include <string>
#include <vector>
using namespace std;
vector<int>answer(2, 0);
vector<vector<int>>board;
int N;

void div(int start_y, int end_y, int start_x, int end_x) {
    if (start_y == end_y) ++answer[board[start_y][start_x]];
    else {
        int prev = board[start_y][start_x];
        for (int y = start_y; y <= end_y; ++y) {
            for (int x = start_x; x <= end_x; ++x) {
                if (prev != board[y][x]) {
                    int mid_y = (start_y + end_y) / 2;
                    int mid_x = (start_x + end_x) / 2;
                    div(start_y, mid_y, start_x, mid_x);
                    div(start_y, mid_y, mid_x + 1, end_x);
                    div(mid_y + 1, end_y, start_x, mid_x);
                    div(mid_y + 1, end_y, mid_x + 1, end_x);
                    return;
                }
                prev = board[y][x];
            }
        }
        ++answer[board[start_y][start_x]];
    }
}

vector<int> solution(vector<vector<int>> board) {
    N = board.size();
    ::board = board;
    div(0, N - 1, 0, N - 1);
    return answer;
}