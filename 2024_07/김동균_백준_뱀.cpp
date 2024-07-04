#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, K, L;
int Map[101][101] = { 0, };
vector<pair<int, char>> moves;
queue<pair<int, int>> snake;

int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

int main() {
    cin >> N >> K;
    for (int i = 0; i < K; i++) {
        int x, y;
        cin >> x >> y;
        Map[x][y] = 1;
    }

    cin >> L;
    for (int i = 0; i < L; i++) {
        int x;
        char c;
        cin >> x >> c;
        moves.push_back({ x, c });
    }

    int x = 1, y = 1, dir = 0, time = 0;
    snake.push({ x, y });
    Map[x][y] = 2;

    for (auto move : moves) {
        while (time < move.first) {
            time++;
            x += dx[dir];
            y += dy[dir];

            if (x < 1 || x > N || y < 1 || y > N || Map[x][y] == 2) {
                cout << time << endl;
                return 0;
            }

            if (Map[x][y] == 1) {
                Map[x][y] = 2;
            }
            else {
                Map[x][y] = 2;
                Map[snake.front().first][snake.front().second] = 0;
                snake.pop();
            }

            snake.push({ x, y });
        }

        if (move.second == 'L') {
            dir = (dir + 3) % 4;
        }
        else {
            dir = (dir + 1) % 4;
        }
    }

    while (true) {
        time++;
        x += dx[dir];
        y += dy[dir];

        if (x < 1 || x > N || y < 1 || y > N || Map[x][y] == 2) {
            cout << time << endl;
            return 0;
        }

        if (Map[x][y] == 1) {
            Map[x][y] = 2;
        }
        else {
            Map[x][y] = 2;
            Map[snake.front().first][snake.front().second] = 0;
            snake.pop();
        }

        snake.push({ x, y });
    }

    return 0;
}
