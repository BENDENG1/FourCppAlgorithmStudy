//문제풀이: https://githubseob.tistory.com/373

#include <string>
#include <vector>
using namespace std;

int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0,-1 };

vector<int> solution(string command) {
    vector<int> answer;
    int dir(0), y(0), x(0);

    for (int idx = 0; idx < command.size(); ++idx) {
        if (command[idx] == 'R') {
            dir = (dir + 1) % 4;
        }
        else if (command[idx] == 'L') {
            dir = (dir + 3) % 4;
        }
        else if (command[idx] == 'G') {
            y += dy[dir];
            x += dx[dir];
        }
        else if (command[idx] == 'B') {
            y += dy[(dir + 2) % 4];
            x += dx[(dir + 2) % 4];
        }
    }

    answer = { x, y };
    return answer;
}