#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n, l, answer = 1;
    vector<int> v;
    
    cin >> n >> l;
    
    for(int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}
    
    sort(v.begin(), v.end());
    
    int start = v[0];
    
    for(int i = 1; i < n; i++){
        if(v[i] - start < l){
            continue;
        }
        start = v[i];
        answer++;
    }
    
    cout << answer;
}