#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    
    int num_size = number.length() - k;
    int start = 0;
    
    for(int i = 0; i < num_size; i++){
        char max_num = number[start];
        int max_idx = start;
        for(int j = start; j <= k + i; j++){
            if(max_num < number[j]){
                max_num = number[j];
                max_idx = j;
            }
        }
        start = max_idx + 1;;
        answer += max_num;
    }
    
    return answer;
}