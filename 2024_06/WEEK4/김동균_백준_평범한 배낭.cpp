#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;
    int W[101]={0}, V[101]={0};
    for (int i = 1; i <= N; i++) {
        cin >> W[i] >> V[i];
    }
    
    int DP[101][100001] = {0}; 

    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j <= K; j++)
        {
            if (j >= W[i])
                DP[i][j] = max(DP[i - 1][j], DP[i - 1][j - W[i]] + V[i]);
            else
                DP[i][j] = DP[i - 1][j];
        }
    }
    cout << DP[N][K];
    return 0;
}
