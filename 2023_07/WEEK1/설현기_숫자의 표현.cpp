#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int lp = 1, rp = lp + 1;
    int sum = 1;
    while(lp != n){
        if(sum == n){
            answer++;
            sum += rp++;
        }
        else if(sum > n){
            sum -= lp++;
        }
        else{
            sum += rp++;
        }
    }
    return ++answer;
}