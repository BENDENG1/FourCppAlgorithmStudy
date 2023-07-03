#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer(2, 0);
    vector<string> usedWords;
    char lastChar = words[0][0];

    for (int i = 0; i < words.size(); i++) {
        if (words[i][0] != lastChar || find(usedWords.begin(), usedWords.end(), words[i]) != usedWords.end()) {
            answer[0] = i % n + 1;
            answer[1] = i / n + 1;
            break;
        }
        usedWords.push_back(words[i]);
        lastChar = words[i].back();
    }

    return answer;
}