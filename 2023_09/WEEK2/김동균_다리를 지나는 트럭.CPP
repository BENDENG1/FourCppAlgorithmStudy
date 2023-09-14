#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int time = 0; // 시간을 초기화
    vector<int> x(bridge_length, 0); // 다리를 나타내는 벡터. 초기에 다리는 비어있음.
    int s = 0; // 다리 위의 총 트럭 무게를 나타내는 변수

    while (!x.empty()) { // 다리에 트럭이 없을 때까지 반복
        time += 1; // 시간 증가
        s -= x[0]; // 다리의 가장 앞 트럭을 빼고, 그 무게를 총 트럭 무게에서 뺀다
        x.erase(x.begin()); // 다리의 가장 앞 트럭을 제거 (큐처럼 동작)

        if (!truck_weights.empty()) { // 대기 중인 트럭이 남아있으면
            if (s + truck_weights[0] <= weight) { // 다리에 트럭을 추가할 여유가 있다면
                s += truck_weights[0]; // 해당 트럭을 다리 위에 추가하고
                x.push_back(truck_weights[0]); // 다리에도 추가한다
                truck_weights.erase(truck_weights.begin()); // 대기 중인 트럭 목록에서 제거
            } else {
                x.push_back(0); // 다리에 트럭을 추가할 여유가 없으면, 다리에 0을 추가 (무게만 유지)
            }
        }
    }

    return time; // 모든 트럭이 다리를 건너는 데 걸린 총 시간 반환
}
