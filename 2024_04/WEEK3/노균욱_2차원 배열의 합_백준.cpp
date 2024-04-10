/*

*/
#include <iostream>

using namespace std;

int arr[301][301];

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n, m, t, tmp;

    cin >> n >> m;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> tmp;
            arr[i][j] = tmp;
        }
    }

    cin >> t;

    for(int i = 0 ; i < t; i++){
        int startY, startX, endY, endX;
        cin >> startY >> startX >> endY >> endX;

        int sum = 0;

        for(int j = startY - 1; j < endY; j++){
            for(int k = startX - 1 ; k < endX; k++){
                sum += arr[j][k];
            }
        }
        cout << sum << "\n";
    }

}