#include <iostream>
#include <map>

using namespace std;

int main(){
    map<string, int> m;
    int cnt = 0;
    string s;
    
    while (getline(cin, s)) {
        m[s]++;
        cnt++;
    }
    
    for (auto i : m) {
        cout << fixed;
        cout.precision(4);
        
        float ans = (float) i.second / cnt;
        cout << i.first << ' ' << ans * 100 << '\n'; 
    }
}