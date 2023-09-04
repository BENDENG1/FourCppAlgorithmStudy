//문제풀이: https://githubseob.tistory.com/326

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<int> topping) {
    int answer(0);
    unordered_map<int, int>types;
    unordered_map<int, int>older;

    for (int idx = 0; idx < topping.size(); ++idx)
        ++types[topping[idx]];

    for (int mid = 0; mid < topping.size(); ++mid) {
        ++older[topping[mid]];
        --types[topping[mid]];
        if (types[topping[mid]] == 0) types.erase(topping[mid]);
        if (older.size() == types.size()) ++answer;
    }

    return answer;
}