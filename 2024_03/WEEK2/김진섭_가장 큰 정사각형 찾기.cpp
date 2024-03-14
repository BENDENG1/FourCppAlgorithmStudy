//문제풀이: https://githubseob.tistory.com/364

#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> board)
{
    int N(board.size()), M(board[0].size());

    vector<vector<int>>sum(N + 1, vector<int>(M + 1, 0));

    for (int y = 1; y <= N; ++y) {
        for (int x = 1; x <= M; ++x) {
            sum[y][x] = sum[y][x - 1] + board[y - 1][x - 1];
        }
    }

    for (int y = 1; y <= N; ++y) {
        for (int x = 1; x <= M; ++x) {
            sum[y][x] += sum[y - 1][x];
        }
    }

    for (int len = min(N, M); len > 0; --len) {
        for (int y = 1; y <= N - len + 1; ++y) {
            for (int x = 1; x <= M - len + 1; ++x) {
                if (sum[y + len - 1][x + len - 1] - sum[y + len - 1][x - 1] - sum[y - 1][x + len - 1] + sum[y - 1][x - 1] == len * len) {
                    return len * len;
                }
            }
        }
    }

    return 0;
}