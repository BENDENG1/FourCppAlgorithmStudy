#include <string>
#include <vector>

using namespace std;

int solution(int storey) {
    int answer = 0;
    int num = 0;
    while(storey != 0){
        num = storey % 10;
        
        if(num > 5){
            answer += (10 - num);
            storey /= 10;
            storey++;
        }
         else if(num == 5) {
            if((storey / 10) % 10 >= 5) {
                answer += (10 - num);
                storey /= 10;
                storey += 1;
            }
            else {
                answer += num;
                storey /= 10;
            }
        }
        else {
            answer += num;
            storey /= 10;
        }
    }
    return answer;
}