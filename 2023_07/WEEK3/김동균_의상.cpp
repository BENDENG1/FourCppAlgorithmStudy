#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string, int> clothes_count;

    // 의상 종류별로 옷의 개수를 세어줍니다.
    for (const auto& cloth : clothes) {
        clothes_count[cloth[1]]++;
    }

    for (const auto& count_pair : clothes_count) {
        answer *= (count_pair.second + 1);
    }

    // 모든 종류의 옷을 입지 않는 경우는 없으므로 1을 뺀다.
    answer -= 1;
    return answer;
}