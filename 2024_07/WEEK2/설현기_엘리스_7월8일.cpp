#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(){
    string s, answer;

    cin >> s;

    if(next_permutation(s.begin(), s.end())){
        answer = s;
    }

    cout << answer;

    return 0;
}
