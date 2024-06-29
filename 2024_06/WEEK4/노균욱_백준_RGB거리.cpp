/*
RGB거리

n에 대한 비용들을 선택해서 최솟값을 만들면 되는거

위아래의 집이 같지 않아야한다.

*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);

    int n;

    cin >> n;
    vector<vector<int>> v(n, vector<int>(n, 0));
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> v[i][j];
        }
    }

    dp[0] = v[0];

    for (int i = 1; i < n; i++){
        dp[i][0] += v[i][0] + min(dp[i - 1][1], dp[i - 1][2]);
        dp[i][1] += v[i][1] + min(dp[i - 1][0], dp[i - 1][2]);
        dp[i][2] += v[i][2] + min(dp[i - 1][0], dp[i - 1][1]);
    }

    cout << min({dp[n-1][0], dp[n-1][1], dp[n-1][2] });
}