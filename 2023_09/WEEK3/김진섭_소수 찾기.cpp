//문제풀이: https://githubseob.tistory.com/190

#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

unordered_set<int>prime;

int solution(string numbers) {

    sort(numbers.begin(), numbers.end());

    do {
        string s_num("");
        for (int idx = 0; idx < numbers.size(); ++idx) {
            s_num += numbers[idx];
            int num = stoi(s_num);
            if (prime.find(num) != prime.end()) continue;
            int mul = 2;
            for (mul = 2; mul * mul <= num; ++mul) {
                if (num % mul == 0) break;
            }
            if (mul * mul > num) prime.insert(num);
        }
    } while (next_permutation(numbers.begin(), numbers.end()));

    if (prime.find(1) != prime.end()) prime.erase(1);
    if (prime.find(0) != prime.end()) prime.erase(0);

    return prime.size();
}