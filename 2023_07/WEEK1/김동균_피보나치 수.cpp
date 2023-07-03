#include <string>
#include <vector>


using namespace std;

int solution(int n) {
    int answer = 0;
    vector <int> a={0,1};
 
    
  
    for(int i=2;i<=n;i++){
        answer = (a[i-2] + a[i-1])%1234567; // 0 + 1 =2 1 + 2
        a.push_back(answer);
    }
  
    return answer;
}