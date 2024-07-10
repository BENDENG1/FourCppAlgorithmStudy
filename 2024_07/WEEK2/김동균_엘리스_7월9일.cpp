#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<int> V(N);
    for (int i = 0; i < N; ++i) {
        cin >> V[i];
    }

    while (M--) {
        int i, j, k;
        cin >> i >> j >> k;
        vector<int*> temp (V.begin() + (i - 1), V.begin() + j); // 부분 벡터 생성
        sort(temp.begin(), temp.end()); // 부분 벡터 정렬
        cout << temp[k - 1] << '\n'; 
    }

    return 0;
}
