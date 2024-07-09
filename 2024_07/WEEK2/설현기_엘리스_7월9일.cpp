#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m, i, j, k, tmp;
    vector<int> v;
    vector<int> num;

    cin >> n >> m;

    for(int idx = 0; idx < n; idx++){
        cin >> tmp;
        v.push_back(tmp);
    }

    for(int cnt = 0; cnt < m; cnt++){
        cin >> i >> j >> k;
        num.clear();
        for(int idx = i - 1; idx < j; idx++){ 
            num.push_back(v[idx]);
        }
        sort(num.begin(), num.end());
        cout << num[k - 1] << endl; 
    }

    return 0;
}
