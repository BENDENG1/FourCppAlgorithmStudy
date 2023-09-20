#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<vector<int>> triangle(n, vector<int>(n, 0));
    vector<int> dx = {0, 1, -1};
    vector<int> dy = {1, 0, -1};
    int v = 1;
    int x = 0;
    int y = 0;
    int d = 0;

    while (true) {
        triangle[y][x] = v++;
        int nx = x + dx[d];
        int ny = y + dy[d];

        if (nx == n || ny == n || triangle[ny][nx] != 0) {
            d = (d + 1) % 3;
            nx = x + dx[d];
            ny = y + dy[d];

            if (nx == n || ny == n || triangle[ny][nx] != 0)
                break;
        }

        x = nx;
        y = ny;
    }

    vector<int> result;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            result.push_back(triangle[i][j]);
        }
    }

    return result;
}
