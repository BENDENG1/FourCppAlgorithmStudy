/*
정수 삼각형

음 dp로 풀면?
1
2
3
4
5
*/
#include <iostream>
#include <algorithm>
int arr[500][500];

using namespace std;

int main (){
    ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);

    int n, tmp, maxSum = 0;

    cin >> n;

    for(int i = 0 ; i < n; i++){
        for(int j = 0; j <= i ; j++){
            cin >> arr[i][j];
            if(i >= 1){
                if(j == 0){
                    arr[i][j] += arr[i -1][j];
                }else if(j == i){
                    arr[i][j] += arr[i - 1][j - 1];
                }else{
                    arr[i][j] += max(arr[i - 1][j], arr[i - 1][j - 1]);
                }
            }
        }
    }

    for(int i = 0; i < n; i++){
        maxSum = maxSum > arr[n - 1][i] ? maxSum : arr[n - 1][i];
    }
    cout << maxSum;
}