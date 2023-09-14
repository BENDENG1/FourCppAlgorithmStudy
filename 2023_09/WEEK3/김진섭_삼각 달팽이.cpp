//문제풀이: https://githubseob.tistory.com/340

#include <string>
#include <vector>
using namespace std;

vector<vector<int>>board;
int num, max_size;
bool isBreak(int y, int x) {
    if (y < 0 || x < 0) return true;
    else if (y >= board.size()) return true;
    else if (x >= board[y].size()) return true;
    else if (board[y][x] != 0) return true;
    else if (num > max_size) return true;
    else return false;
}

vector<int> solution(int N) {
    vector<int> answer;

    board = vector<vector<int>>(N);

    for (int y = 0; y < N; ++y) {
        board[y] = vector<int>(y + 1, 0);
        max_size += y + 1;
    }

    int y(0), x(0);

    while (1) {
        if (num >= max_size) break;
        while (1) {
            if (isBreak(y, x) == false) {
                board[y][x] = ++num;
                ++y;
            }
            else {
                --y;
                ++x;
                break;
            }
        }
        while (1) {
            if (isBreak(y, x) == false) {
                board[y][x] = ++num;
                ++x;
            }
            else {
                x -= 2;
                --y;
                break;
            }
        }
        while (1) {
            if (isBreak(y, x) == false) {
                board[y][x] = ++num;
                --y;
                --x;
            }
            else {
                y += 2;
                x += 1;
                break;
            }
        }
    }

    for (int y = 0; y < N; ++y) {
        for (int x = 0; x <= y; ++x) {
            answer.push_back(board[y][x]);
        }
    }

    return answer;
}