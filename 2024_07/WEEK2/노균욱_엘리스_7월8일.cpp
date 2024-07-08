#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    string s, ans;
     
    cin >> s;

    if(next_permutation(s.begin(), s.end())) {
        cout << s;
    }
}
