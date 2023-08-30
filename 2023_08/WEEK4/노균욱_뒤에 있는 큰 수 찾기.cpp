 /*
 answers벡터에 대해서 numbers.size()만큼 -1로 초기화를 해준다. 
 stack에 넣어버린다 -> top에 대해서 만약에 큰값이 나온다? -> stack에 쌓여있는 그것보다 작은값에 대해서 pop을 반복
 
 결국 -1을 안해도 애초에 -1을 초기화 해버렸기 때문에 그냥 가능
 */
#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer(numbers.size(), -1);
    stack<pair<int,int>> s;
    
    for(int i = 0;i<numbers.size();i++){
        while(!s.empty()){
            int num = s.top().first;
            int idx = s.top().second;
            
            if(num < numbers[i]){
                answer[idx] = numbers[i];
                s.pop();
            }else{
                break;
            }
        }
        s.push(make_pair(numbers[i],i));
    }
    
    return answer;
}