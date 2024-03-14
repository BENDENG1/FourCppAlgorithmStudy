#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    int Start = 0, End = 0;
    int sum = sequence[0]; // 부분 수열의 합
    int subLen = sequence.size() + 1; // 부분 수열의 길이
    vector<int> answer;
    
    while (Start <= End && End < sequence.size()) {
        if (sum < k) sum += sequence[++End];
        else if (sum == k) {
            if (End - Start + 1 < subLen) { // 길이가 더 짧은 수열이면
                subLen = End - Start + 1;
                answer = {Start, End};
            } else if (End - Start + 1 == subLen) {
                if (Start < answer[0]) { // 시작 인덱스가 더 작으면
                    answer = {Start, End};
                }
            }
            
            sum -= sequence[Start++];
        } 
        else sum -= sequence[Start++];
    }
    
    return answer;
}