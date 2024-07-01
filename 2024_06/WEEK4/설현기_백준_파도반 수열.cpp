#include <iostream>
using namespace std;

int main(){
    int t, n;
    long long dp[101] = {0};
    dp[1] = dp[2] = dp[3] = 1;
    dp[4] = dp[5] = 2;
    dp[6] = 3;
    
    cin >> t;
    
    while(t--){
        cin >> n;
        
        if(n <= 6)
            cout << dp[n] << "\n";
        else{
            for(int i = 7; i <= n; i++){
                dp[i] = dp[i - 1] + dp[i - 5];
            }
            cout << dp[n] << "\n";
        }
    }  
    return 0;
}