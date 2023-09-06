#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    
    for (int idx = 0; idx < prices.size(); ++idx){ // 하나씩 가져와서
        int chk = 0;
        for(int i = idx+1; i < prices.size(); ++i){
            chk++;
            if(prices[idx] > prices[i]) // 비교한다
                break;
            }
        answer.push_back(chk); // answer에 넣는다
    }
    return answer;
}
