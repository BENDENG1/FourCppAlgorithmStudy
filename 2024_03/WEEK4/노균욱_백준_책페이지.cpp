/*
책 페이지

전체페이지 n => 1~n페이지 

0,1,2...9까지 총 몇번 나오는지 공백으로 출력

*/
#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    long long n;
    int arr[10] = {0,};
    int digit = 1,before = 0;

    cin >> n;

    while(n != 0){
        long long remain = n % 10;
        n /= 10;

        arr[0] -= digit;
        for(int j = 0; j < remain ;j++)
            arr[j] += (n + 1) * digit;
        arr[remain] += n * digit + 1 + before;
        for(int j = remain + 1; j <= 9; j++)
            arr[j] += n * digit;
        before += remain * digit;

        digit *= 10;
    }

    for(int i = 0 ; i < 10; i++){
        cout<< arr[i] << " ";
    }

}