#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    uint16_t DP[1001][3];
    uint16_t RGB[1001][3];
    int N;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> RGB[i][j];
        }
    }

    // 초기화
    DP[0][0] = RGB[0][0];
    DP[0][1] = RGB[0][1];
    DP[0][2] = RGB[0][2];

    for (int i = 1; i < N; i++) {
        DP[i][0] = RGB[i][0] + min(DP[i - 1][1], DP[i - 1][2]);
        DP[i][1] = RGB[i][1] + min(DP[i - 1][0], DP[i - 1][2]);
        DP[i][2] = RGB[i][2] + min(DP[i - 1][0], DP[i - 1][1]);
    }

    cout << min({ DP[N - 1][0], DP[N - 1][1], DP[N - 1][2] }) << endl;

    return 0;
}
