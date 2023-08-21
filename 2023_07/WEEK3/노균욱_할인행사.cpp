#include <string>
#include <vector>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    
    for(int i = 0; i <= discount.size() - 10;i++){
        vector<int> v = number;
        int flag = 1;
        
        for(int j= 0 ; j < 10;j++){
            for(int k = 0; k < v.size();k++){
                if(want[k] == discount[i + j] && v[k] > 0)
                    v[k]--;
            }
        }
        
        for(int j = 0; j < v.size();j++){
            if(v[j] > 0){
                flag = 0;
                break;
            }
        }
        if(flag == 1)
            answer += 1;
    }
    
    return answer;
}