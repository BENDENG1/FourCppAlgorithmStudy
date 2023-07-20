#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    int n = discount.size();

    for (int i = 0; i <= n - 10; i++) { // 10일 동안의 반복
        int j;
        for (j = 0; j < want.size(); j++) {
            int check = 0;
            for (int k = i; k < i + 10; k++) { // 행사 사이클에서의 각 날짜를 순회
                if (discount[k] == want[j]) { // 할인하는 제품이 정현이가 원하는 제품인 경우
                    check++; // 해당 제품의 수량을 증가시킴
                }
            }
            if (check < number[j]) { // 10일 동안 원하는 제품의 수량을 할인받지 못하는 경우
                break; // 더 이상 해당 행사 사이클은 고려하지 않음
            }
        }
        if (j == want.size()) { // 모든 원하는 제품에 대해 10일 동안 할인을 받을 수 있는 경우
            answer++; // 날짜 수를 증가시킴
        }
    }
    return answer; // 총  날짜 수를 반환
}
