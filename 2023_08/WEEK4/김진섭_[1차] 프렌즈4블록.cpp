//문제풀이: https://githubseob.tistory.com/319

#include <string>
#include <vector>
#include <algorithm>
#include <set>
#define pii pair<int, int>
using namespace std;
vector<string>board;
set<pii>loc;

void findBlocks(int y, int x) {
    if (y - 1 < 0 || x >= board[y].size()) return;

    char c1 = board[y][x];
    char c2 = board[y][x + 1];
    char c3 = board[y - 1][x];
    char c4 = board[y - 1][x + 1];

    if (c1 == '0') return;
    if (c1 == c2 && c1 == c3 && c1 == c4) {
        loc.insert({ y, x });
        loc.insert({ y, x + 1 });
        loc.insert({ y - 1, x });
        loc.insert({ y - 1, x + 1 });
    }
}

void eraseBlocks() {
    for (auto iter = loc.begin(); iter != loc.end(); ++iter) {
        board[iter->first][iter->second] = '0';
    }

    for (int y = board.size() - 1; y >= 0; --y) {
        for (int x = 0; x < board[y].size(); ++x) {
            if (board[y][x] == '0') {
                int ny = y - 1;
                while (ny >= 0 && board[ny][x] == '0') --ny;
                if (ny < 0) continue;
                else {
                    swap(board[y][x], board[ny][x]);
                }
            }
        }
    }
}

int solution(int m, int n, vector<string> board) {
    int answer(0);
    ::board = board;

    loc.insert({ -1,-1 });
    while (!loc.empty()) {
        loc.clear();
        for (int y = board.size() - 1; y >= 0; --y) {
            for (int x = 0; x < board[y].size(); ++x) {
                findBlocks(y, x);
            }
        }
        answer += loc.size();
        eraseBlocks();
    }
    return answer;
}