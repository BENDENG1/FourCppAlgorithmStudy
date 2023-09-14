#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int idx = 0;
    int sum = 0;
    queue<int> q;
    
    while(true){
        if(idx == truck_weights.size()){
            answer += bridge_length;
            break;
        }
        
        int tmp = truck_weights[idx];
        answer++;
        
        if(sum + tmp <= weight){
            sum += tmp;
            q.push(tmp);
            idx++;
        }
        else{
            q.push(0);
        }
        
        if(q.size() == bridge_length){
            sum -= q.front();
            q.pop();
        }
    }
    
    return answer;
}