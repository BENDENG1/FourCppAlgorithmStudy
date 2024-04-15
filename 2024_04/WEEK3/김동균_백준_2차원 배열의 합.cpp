//배열의 크기 N M
//N개의 줄에는(2)
//M개의 정수로 배열(3)
//즉	) 1 2 4
//) 8 16 32 배열
//합을 구할 부분의 개수 K(3)
//1, 1에서 2, 3까지의 합
//1 2 4 8 16 32
//1 2 에서 1 2 까지의 합 )
//2
//1 3 에서 2 3 까지의 합
//4 8 16 32

#include <iostream>
#include <vector>
using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;
    vector<vector<int>> Board(N, vector<int>(M));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> Board[i][j];
        }
    }

    int K;
    cin >> K;
    while (K--) {
        int i, j, x, y;
        cin >> i >> j >> x >> y;
        long long sum = 0; // 구간 합을 저장할 변수
        for (int a = i - 1; a < x; a++) {
            for (int b = j - 1; b < y; b++) {
                sum += Board[a][b];
            }
        }
        cout << sum << endl;
    }

    return 0;
}

