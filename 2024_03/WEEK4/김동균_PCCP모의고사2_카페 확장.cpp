#include <string>
#include <vector>
#include <queue>
#include <deque>

using namespace std;

int solution(vector<int> menu, vector<int> order, int k) {
    vector<int> Vector(1, 0); // 고객의 대기 순서를 관리하는 큐의 인덱스
    int begin = 0;  // 현재 처리 중인 고객의 위치를 나타내는 인덱스
    int customerIndex = 1;  // 다음에 처리할 고객의 인덱스
    int NowTime = 0;  // 현재 시간
    int answer = 0;  // 최대 대기열 크기를 저장

    // 대기열이 끝나지 않았다면 반복
    while (begin < (int)Vector.size()) {
        int NowOrder = Vector[begin];  // 현재 처리 중인 주문의 인덱스
        // 고객의 주문 시간이 현재 시간보다 이전이라면, 현재 시간에 메뉴 조리 시간을 더함
        if (k * NowOrder < NowTime) {
            NowTime += menu[order[NowOrder]];
        }
        else {
            // 그렇지 않다면, 고객의 주문 시간에 메뉴 조리 시간을 더해 현재 시간을 업데이트
            NowTime = k * NowOrder + menu[order[NowOrder]];
        }

        // 다음 고객의 주문 처리: 현재 시간 이전에 주문한 모든 고객을 대기열에 추가
        while (customerIndex < (int)order.size() && k * customerIndex < NowTime) {
            Vector.push_back(customerIndex);
            customerIndex += 1;
        }

        // 최대 대기열 크기 업데이트
        answer = max(answer, (int)Vector.size() - begin);
        // 다음 고객으로 이동
        begin += 1;

        // 모든 고객이 처리되었을 때, 아직 대기열에 남아있는 고객이 없다면 새 고객 추가
        if (begin == (int)Vector.size() && customerIndex < (int)order.size()) {
            Vector.push_back(customerIndex);
            customerIndex += 1;
        }
    }
    return answer;
}

