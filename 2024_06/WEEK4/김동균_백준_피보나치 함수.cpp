//DP쓰는 피보나치
//규칙이 있다
//0 1 2를 제외하고
//3부터는 2 하고 1의 조합
//4는 3 2 1 조합

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int DP[41] = {0,};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin >> T;
    
    DP[0] = 1;
    DP[1] = 1;
    DP[2] = 1;
    for (int i = 3; i < 41; i++)
    {
        DP[i] = DP[i - 1] + DP[i - 2];
    }

    while (T--)
    {
        int N;
        cin >> N;
        if (N==0)
        {
            cout << '1' << " " << '0' << endl;
        }
        else if (N == 1)
        {
            cout << '0' << " " << '1' << endl;
        }
        else
        {
            cout << DP[N - 1] << " " << DP[N] << endl;
        }
    }
}