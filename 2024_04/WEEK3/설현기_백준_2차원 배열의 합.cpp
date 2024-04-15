#include <iostream>

using namespace std;

int main() {
    int v[301][301];
    int n, m, k;
    
    cin >> n >> m;
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> v[i][j];
            v[i][j] += v[i][j - 1] + v[i - 1][j] - v[i - 1][j - 1];
        }
    }
    
    cin >> k;
    
    for(int i = 0; i < k; i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << v[c][d] - v[a - 1][d] - v[c][b - 1] + v[a - 1][b - 1] << '\n';
    }
    
    return 0;
}