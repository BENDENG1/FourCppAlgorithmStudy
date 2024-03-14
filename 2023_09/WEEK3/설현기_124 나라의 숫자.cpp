#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    int rem = 0;
    int num = n;
    
    while(num != 0){
        rem = num % 3;
        num /= 3;
        
        if(rem == 0){
            answer = "4" + answer;
            num--;
        }
        else if(rem == 1){
            answer = "1" + answer;
        }
        else if(rem == 2){
            answer = "2" + answer;
        }
    }
    return answer;
}