//문제풀이: https://githubseob.tistory.com/329

#include <string>
#include <vector>
#include <bitset>
#define ll long long
using namespace std;


vector<ll> solution(vector<ll> numbers) {
    vector<ll> answer(numbers.size(), 0);

    for (int num_idx = 0; num_idx < numbers.size(); ++num_idx) {
        bitset<60>num = numbers[num_idx];
        for (int idx = 0; idx < 60; ++idx) {
            if (num.test(idx) == 0) {
                num.flip(idx);
                if (idx != 0)
                    num.flip(idx - 1);
                answer[num_idx] = num.to_ullong();
                break;
            }
        }
    }

    return answer;
}