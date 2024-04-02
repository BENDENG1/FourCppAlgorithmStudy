#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int n = 0, budget = 0, low = 0, high = 0, result = 0;
    
    cin >> n;
    vector<int> v;
    
    for(int i = 0; i < n; i++){
        int temp; 
        cin >> temp;
        v.push_back(temp); 
    }
    
    cin >> budget;
    
    sort(v.begin(), v.end());
    
    high = v[n - 1];
    
    while(low <= high){
        int mid = (low + high) / 2;
        int sum = 0;
        
        for(int i = 0; i < n; i++){
            if(v[i] > mid){
                sum += mid;
            }
            else{
                sum += v[i];
            }
        }
        
        if(sum > budget){
            high = mid - 1;
        }
        else{
            result = max(result, mid);
            low = mid + 1;
        }
    }
    
    cout << result << '\n';
    
    return 0;
}