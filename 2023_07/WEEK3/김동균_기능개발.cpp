#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
  vector<int> answer;
    int n = progresses.size();
    int day = 0; // 현재까지 지난 날짜

    while (!progresses.empty()) {
        // 각 작업의 진도를 개발 속도에 맞게 더해줌
        for (int i = 0; i < n; ++i) {
            progresses[i] += speeds[i];
        }
        int count = 0; // 현재 배포 가능한 작업 수

        // 배포 가능한 작업 수 계산
        while (!progresses.empty() && progresses.front() >= 100) {
            progresses.erase(progresses.begin());
            speeds.erase(speeds.begin());
            ++count;
        }

        if (count > 0) {
            answer.push_back(count);
            day = 0; // 배포 가능한 작업이 있으면 날짜 초기화
        } else {
            ++day; // 배포 가능한 작업이 없으면 날짜 추가
        }
    }

    return answer;
}