/*
집합의 표현

합집합 만들고 

아 그냥 낮거나 높은 숫자로 합해버리면 되네
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> v;

int getGroup(int num){
    if(v[num] == num) return num;
    return v[num] = getGroup(v[num]);
}


int main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n, m;

    cin >> n >> m;
    v.resize(n + 1, 0);

    for(int i = 1 ; i <=n; i++){
        v[i] = i;
    }
    for(int i = 0 ; i < m; i++){
        int ox,a,b;
        cin >> ox >> a >> b;
        if(ox == 0){
            a = getGroup(a);
            b = getGroup(b);
            if(a < b)
                v[a] = b;
            else
                v[b] = a;
        }else{
            a = getGroup(a);
            b = getGroup(b);
            if(a == b){
                cout<<"YES\n";
            }else{
                cout <<"NO\n";
            }
        }
    }

}