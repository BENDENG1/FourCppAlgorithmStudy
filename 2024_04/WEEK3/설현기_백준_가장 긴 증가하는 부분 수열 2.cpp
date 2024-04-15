#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, a;
    vector<int> v, ans;
    
    cin >> n;
    
    for(int i = 0; i < n; i++){
        cin >> a;
        v.push_back(a);
    }
    ans.push_back(v[0]);
    for(int i = 1; i < n; i++){
        if(ans.back() < v[i]){
            ans.push_back(v[i]);
        }
        else{
            int idx = lower_bound(ans.begin(), ans.end(), v[i]) - ans.begin();
            ans[idx] = v[i];
        }
    }
    
    cout << ans.size();
}