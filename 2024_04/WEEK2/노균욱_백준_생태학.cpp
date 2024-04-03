/*
생태학
*/
#include <iostream>
#include <map>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cout << fixed;
    cout.precision(4);

    string str;
    int cnt = 0;
    map<string, float> m;

    while(getline(cin,str)){
        cnt++;
        m[str]++;
    }
    
    for(auto tmp = m.begin(); tmp != m.end(); tmp++){
        cout << tmp -> first << " " << (tmp -> second) * 100 / cnt <<"\n";
    }

}

