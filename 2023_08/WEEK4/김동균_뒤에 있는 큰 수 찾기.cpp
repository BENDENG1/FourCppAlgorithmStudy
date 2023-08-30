#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer(numbers.size(), -1);

    for (int i = 0; i < numbers.size(); i++) {
        for (int j = i + 1; j < numbers.size(); j++) {
            if (numbers[j] > numbers[i]) {
                answer[i] = numbers[j];
                break;
            } else if (numbers[i] >= numbers[j]) {
                if (answer[j] == -1) {
                    answer[i] = -1;
                    break;
                } else if (numbers[i] < answer[j]) {
                    answer[i] = answer[j];
                    break;
                }
            }
        }
    }

    return answer;
}