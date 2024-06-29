/*
파도반 수열 

가장 큰 긴변의 길이 k 정삼각형 추가
dp
1 1 1 2 2 3 4 5 7 9 12 16..
arr[n] = arr[n - 2] + arr[n - 3]

*/
#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);

    int t, n;
    long long dp[102] = {0,1,1,1,};

    cin >> t;

    for(int i = 4; i <= 100; i++){
        dp[i] = dp[i - 2] + dp[i - 3];
    }

    for(int i = 0 ; i < t; i++){
        cin >> n;
        cout << dp[n] <<"\n";
    }
}