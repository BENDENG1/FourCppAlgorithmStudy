/*
RGB거리

n에 대한 비용들을 선택해서 최솟값을 만들면 된느거임

*/
#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);

    int n;

    cin >> n;
    vector<vector<int>>v(0,vector<int>(n,0));

    for(int i = 0 ; i < n; i++){
        for(int j = 0 ; j < n; j++){
            cin >> v[i][j];
        }
    }
}