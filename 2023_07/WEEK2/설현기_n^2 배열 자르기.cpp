#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    int a = 0;
    int b = 0;
   
    for(long long i = left; i <= right; i++){
        a = i / n;
        b = i % n;
        
        if(a >= b) answer.push_back(a + 1);
        else answer.push_back(b + 1);
    }
    return answer;
}