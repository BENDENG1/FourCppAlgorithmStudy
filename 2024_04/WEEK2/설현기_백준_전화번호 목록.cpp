#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
 
int main(){
    int t;
    cin >> t;
    
    for(int i = 0; i < t; i++){
        int n;
        cin >> n;
        string s;
        vector<string> v;
        for(int j = 0; j < n; j++){
            cin >> s;
            v.push_back(s);
        }
        sort(v.begin(), v.end());
        bool flag = true;
        for(int k = 0; k < v.size() - 1; k++){
            if(v[k].length() > v[k + 1].length()){
                continue;
            }
            if(v[k] == v[k + 1].substr(0, v[k].length())){
                flag = false;
                break;
            }
        }
        if(!flag){
            cout << "NO" << "\n"; 
        }
        else{
            cout << "YES" << "\n";
        }
    }
    
    return 0;
}