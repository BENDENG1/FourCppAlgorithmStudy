#include <iostream>
using namespace std;

int main(){
    int fibo[42][2] = {0, };
    int t, n;
    
    cin >> t;
    
    fibo[1][1] = 1;
    fibo[0][0] = 1;
    
    for(int i = 2; i <= 40; i++){
        fibo[i][0] = fibo[i - 1][0] + fibo[i - 2][0];
        fibo[i][1] = fibo[i - 1][1] + fibo[i - 2][1];
    }
    
    while(t--){
        cin >> n;
        cout << fibo[n][0] << ' ' << fibo[n][1] << '\n';
    }
    
    return 0;
}