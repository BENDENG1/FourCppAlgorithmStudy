#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n(0), m(0);

    cin >> n >> m;
    vector<int>original(n, 0);

    for (int idx = 0; idx < n; ++idx) {
        cin >> original[idx];
    }

    int i(0), j(0), k(0);

    for (int mIdx = 0; mIdx < m; ++mIdx) {
        cin >> i >> j >> k;
        --i, --j, --k;
        vector<int>numbers(j - i + 1, 0);
        for (int idx = 0; idx < numbers.size(); ++idx) {
            numbers[idx] = original[i++];
        }
        sort(numbers.begin(), numbers.end());
        cout << numbers[k] << '\n';
    }
}