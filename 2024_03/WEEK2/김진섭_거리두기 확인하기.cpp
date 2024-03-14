//문제풀이: https://githubseob.tistory.com/189

#include <string>
#include <vector>
using namespace std;

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer(places.size(), 1);    

    for (int idx = 0; idx < places.size(); ++idx) {
        int N = places[idx].size();
        int M = places[idx][0].size();
        for (int y = 0; y < N; ++y) {
            for (int x = 0; x < M; ++x) {
                if (places[idx][y][x] == 'X') continue;

                int cnt(0);
                if (places[idx][y][x] == 'P') ++cnt;
                for (int move = 0; move < 4; ++move) {
                    int ny = y + dy[move];
                    int nx = x + dx[move];
                    if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
                    if (places[idx][ny][nx] == 'P') ++cnt;
                }
                if (cnt > 1) {
                    answer[idx] = 0;
                    y = places[idx].size();
                    break;
                }
            }
        }
    }

    return answer;
}
