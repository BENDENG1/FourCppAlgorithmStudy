#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    for(int i = 0; i < prices.size(); i++){
        int j = i + 1;
        while(j < prices.size()){
            if(prices[i] > prices[j++]){
                break;
            }
        }
        answer.push_back(j - i - 1);
    }
    
    return answer;
}