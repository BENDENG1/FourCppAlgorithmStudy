/*
다리를 지나는 트럭

bridge_length대 올라갈 수 있으며 다리는 weight이하까지 무게를 견딤 (완전히 안오르면 무시)

1. 처음 지나갈때 계속 push_back을 해줌 
2. 이제 길이가 다 찼으면 하나씩 vector에서 맨 앞을 erase하면서 원소를 추가시켜줌
   1) 무게가 안된다? 0 push_back + answer++;
   2) 무게가 된다? 트럭 무게 push_back + answer++;
3. 마지막 트럭이 오게되면 그것에 대해서 길이만큼 다리의 길이만큼 push_back을 하고 끝
*/
#include <string>
#include <vector>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int bridge_weight = 0;
    int idx = 0;
    vector<int> bridges;
    
    while(1){
        if(idx == truck_weights.size()){
            answer += bridge_length;
            break;
        }
        answer++;
        if(bridges.size() == bridge_length){
            bridge_weight -= bridges[0];
            bridges.erase(bridges.begin());
        }
        
        if(bridge_weight + truck_weights[idx] <= weight){
            bridge_weight += truck_weights[idx];
            bridges.push_back(truck_weights[idx]);
            idx++;
        }else
            bridges.push_back(0);
    }
    return answer;
}