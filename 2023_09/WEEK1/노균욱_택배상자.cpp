/*
1~n번 상자 / 한방향 / 보조컨베이어 -> LIFO 

결국 일단 순서대로 실어야함

43125 -> 1,2,3(보조) / 4(트럭) / 3(보조->트럭) / 5,2둘다 자기차례가 아니고 1이어야하는데 없음 -> 끝 
결국 order[i]번째를 먼저 실어라 라는 소리
*/

#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    stack<int> s;
    
    for(int i = 0; i < order.size();i++){
        s.push(i + 1);
        
        while(!s.empty() && s.top() == order[answer]){
            s.pop();
            answer++;
        }
    }
    
    return answer;
}