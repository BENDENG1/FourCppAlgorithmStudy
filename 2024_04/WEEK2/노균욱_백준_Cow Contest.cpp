/*
cow contest

1~n 기술등급이 있음

높은게 무조건 이김
n,m입력값 

*/
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
#define MAX 101

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, m, a, b;
    int ans = 0,cnt = 0;
    int cowArr[MAX][MAX];
    int arr[MAX] = {0,};

    cin >> n >> m;

    for(int i = 1; i <= n;i++){
        for(int j = 1; j<= n ; j++){
            cowArr[i][j] = MAX;
        }
    }

    for(int i = 0; i < m;i++){
        cin >> a >> b;
        cowArr[a][b] = 1;
    }

    for(int i = 1; i <= n ; i++){
        for(int j = 1; j <= n; j++){
            for(int k = 1; k <= n; k++)
                cowArr[j][k] = min(cowArr[j][k], cowArr[j][i] + cowArr[i][k]);
        }
    }

    for(int i = 1; i <= n; i++){
        cnt = 0;
        for(int j = 1; j <= n; j++){
            if(cowArr[i][j] != MAX|| cowArr[j][i] != MAX)
                // cout<<cowArr[i][j]<<" ";
                cnt++;
        }
        // cout<<"\n";
        //cout<<n<<"  "<<cnt<<"\n";
        ans = cnt == n - 1 ? ans + 1 : ans;
    }

    cout << ans;
}