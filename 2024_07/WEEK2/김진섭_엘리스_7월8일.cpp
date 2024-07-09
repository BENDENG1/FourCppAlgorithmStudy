#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string N("");
    cin >> N;

    vector<int>number(N.size(), 0);
    for (int idx = 0; idx < N.size(); ++idx) {
        number[idx] = N[idx] - '0';
    }

    next_permutation(number.begin(), number.end());
    for (int idx = 0; idx < number.size(); ++idx) {
        cout << number[idx];
    }
}