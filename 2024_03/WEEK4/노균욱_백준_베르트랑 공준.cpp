/*
n에서 2n 사이의 소수를 구하는 문제

제곱까지 계산하면 끝 아닌가?
*/

#include <iostream>
#include <cmath>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n, cnt;

    while(1){
        cin>> n;
        
        if(n == 0)
            break;
        cnt = 0;
        for(int i = n + 1; i <= 2 * n;i++){
            bool isDivide = false;
            for(int j = 2; j * j <= i; j++){
                if(i % j == 0){
                    isDivide = true;
                    break;
                }
            }
            if(!isDivide) cnt++;
        }
        cout << cnt << "\n";
    }
    return 0;
}