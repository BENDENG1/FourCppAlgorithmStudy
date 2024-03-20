#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<string> solution(vector<vector<int>> queries) {
    vector<string> answer;
    string Kong[] = {"RR", "Rr", "Rr", "rr"};
    
    for(auto q : queries){
        if(q[0] == 1){
            answer.push_back("Rr");
        }
        
        int value = q[1] - 1;
        
        for(int i = q[0]; i > 1; i--){
            int target = value / (int)(pow(4, (i - 2)));
            
            if(target == 0){
                answer.push_back("RR");
                break;
            }
            else if(target == 3){
                answer.push_back("rr");
                break;
            }
            
            if(i == 2){
                answer.push_back(Kong[target]);
                break;
            }
            
            value %= (int)(pow(4, (i - 2)));
        }
    }
    
    return answer;
}

//중요한건 
//a--
//b/4 %4
//부모를 찾을 수있다.


