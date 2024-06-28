/*
피보나치 함수

0불려지는 횟수 1이 불려지는 횟수

*/

#include <iostream>

using namespace std;

struct Fibo{
    int zero;
    int one;
};

int main(){
    ios_base::sync_with_stdio(0),cin.tie(NULL),cout.tie(NULL);

    int t, num;
    Fibo arr[41] = {{1,0}, {0,1}};
    cin >> t;

    for(int i = 2; i <= 40; i++){
        arr[i].zero = arr[i - 1].zero + arr[i - 2].zero;
        arr[i].one = arr[i - 1].one + arr[i - 2].one;
    }

    for(int i = 0 ; i < t; i++){
        cin >> num;
        cout << arr[num].zero <<" " << arr[num].one<<"\n";
    }
}