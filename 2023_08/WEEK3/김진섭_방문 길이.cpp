//문제풀이: https://githubseob.tistory.com/315

#include <string>
#include <vector>
#define pii pair<int, int>
using namespace std;

int visited[11][11][4];
int answer;

bool isEnd(int y, int x) {
    if (y < 0 || y>10 || x < 0 || x>10) return false;
    else return true;
}

void isVisit(int y, int x, char dir) {
    if (dir == 'U') {
        if (visited[y][x][0] == false) {
            visited[y][x][0] = true;
            visited[y + 1][x][1] = true;
            ++answer;
        }
    }
    else if (dir == 'D') {
        if (visited[y][x][1] == false) {
            visited[y][x][1] = true;
            visited[y - 1][x][0] = true;
            ++answer;
        }
    }
    else if (dir == 'L') {
        if (visited[y][x][2] == false) {
            visited[y][x][2] = true;
            visited[y][x + 1][3] = true;
            ++answer;
        }
    }
    else if (dir == 'R') {
        if (visited[y][x][3] == false) {
            visited[y][x][3] = true;
            visited[y][x - 1][2] = true;
            ++answer;
        }
    }
}

int solution(string dirs) {
    int y(5), x(5);

    for (int idx = 0; idx < dirs.size(); ++idx) {
        if (dirs[idx] == 'U') {
            if (isEnd(y - 1, x) == false) continue;
            else y -= 1;
        }
        else if (dirs[idx] == 'D') {
            if (isEnd(y + 1, x) == false) continue;
            else y += 1;
        }
        else if (dirs[idx] == 'L') {
            if (isEnd(y, x - 1) == false) continue;
            else x -= 1;
        }
        else if (dirs[idx] == 'R') {
            if (isEnd(y, x + 1) == false) continue;
            else x += 1;
        }
        isVisit(y, x, dirs[idx]);
    }

    return answer;
}