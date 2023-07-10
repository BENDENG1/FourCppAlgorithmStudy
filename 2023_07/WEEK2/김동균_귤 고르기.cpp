#include <string>
#include <vector>
#include <algorithm>
#include<map>
using namespace std;

int solution(int k, vector<int> tangerine) {
   int answer = 0;
    map <int, int> counting; // 맵 선언
    vector<int> test; // 백터 선언
    int temp = 0;
    
    for(auto i : tangerine)
    {
        counting[i]++;
    }
    
    for(auto i : counting)
    {
        test.push_back(i.second); 
    }
    
    sort(test.begin(), test.end());
    
    for(int i = test.size() - 1; i >= 0; i--)
    {
        temp += test[i];
        if(temp >= k)
        {
            return test.size() - i;
        }
    }
    
    return answer;
}