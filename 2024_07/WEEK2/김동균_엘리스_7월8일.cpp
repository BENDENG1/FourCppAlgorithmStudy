#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    string str; cin >> str;
    if (next_permutation(str.begin(), str.end()))
        cout << str << '\n';
    /*else
        cout << 0 << '\n';*/
}