//문제풀이: https://githubseob.tistory.com/265

#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer(0), left(0), right(0);

    sort(people.begin(), people.end());

    right = people.size() - 1;

    while (left <= right) {
        if (left == right) {
            ++answer;
            return answer;
        }
        else if (people[left] + people[right] <= limit) {
            ++left;
            --right;
        }
        else if (people[left] + people[right] > limit) {
            --right;
        }
        ++answer;
    }
    return answer;
}