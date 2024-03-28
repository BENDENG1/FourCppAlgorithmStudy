#include <iostream>

using namespace std;

bool isPrime(const int &n){
    if(n == 1){
        return false;
    }
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}

int main(void){
    int n = 1, cnt = 0;
    
    while(n != 0){
        cin >> n;

        if(n == 0) break;
        cnt = 0;
        
        for(int i = n + 1; i <= (n * 2); i++){
            if(isPrime(i)){
                cnt++;
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}