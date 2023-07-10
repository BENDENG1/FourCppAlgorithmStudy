#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(),citations.end());
    
    for (int i = 0; i < citations.size(); i++) {
        answer = citations.size() - i;
        if (citations[i] >= answer) return answer;
    }
    return 0;
}