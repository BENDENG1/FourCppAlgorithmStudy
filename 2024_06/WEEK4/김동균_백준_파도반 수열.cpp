//크기를 너무 작게봤다..
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    size_t DP[101] = { 0,1,1,1 };

    for (int i = 4; i < 101; i++)
    {
        DP[i] = DP[i - 2] + DP[i - 3];
    }
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        cout << DP[N] << '\n'; 
    }

    return 0;
}
