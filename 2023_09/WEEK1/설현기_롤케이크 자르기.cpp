#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    map<int, int> m1, m2;
    int n=topping.size();
    
    for(int i = 0; i < n; i++) m2[topping[i]]++;
    
    for(int i = 0; i < n; i++){
        int m = topping[i];
        
        m1[m]++;
        m2[m]--;
        
        if(m2[m] == 0) m2.erase(m);
        if(m1.size() == m2.size()) answer++;
    }
    
    return answer;
}