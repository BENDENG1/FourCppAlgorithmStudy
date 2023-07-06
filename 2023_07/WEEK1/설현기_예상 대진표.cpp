/*두 수 모두 +1 하고 2 나누기를 반복하다보면 같은수가 되는데, 
그 시점이 둘이 만난 시점이다. ((4, 7) -> (2, 4) -> (1, 2) - > (1, 1)) */ 
#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;
    while(true){ 
        answer++;
        a = (a + 1) / 2;
        b = (b + 1) / 2;
        if(a == b)
            break;
    }
    
    return answer;
}