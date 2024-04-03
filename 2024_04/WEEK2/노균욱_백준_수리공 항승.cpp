/*
수리공 항승

길이가 L인 테이프 

좌우 0.5간격을 줘야 안샘

*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, l, tmp, cnt = 0;

    cin >> n >> l;

    vector<int> v;

    for(int i = 0 ; i < n; i++){
        cin >> tmp;
        v.push_back(tmp);
    }

    sort(v.begin(), v.end());

    for(int i = 0 ; i < v.size(); i++){
        int start = v[i];
        while(i + 1 < v.size() && v[i + 1] < start + l){
            i++;
        }
        cnt++;
    }

    cout << cnt;
}