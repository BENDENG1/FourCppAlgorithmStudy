#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    vector<int> v;
    
    v.push_back(1);
    v.push_back(2);
    
    for(int i =2;i<n;i++){
        v.push_back((v[i-1] + v[i-2]));
    }
    return v[n-1];
}