#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> menu, vector<int> order, int k) {
    int answer = 0;
    int idx = 0, complete = -1;
    queue<int> q;
    
    for(int i = 0; i <= (order.size() - 1) * k; i++){
        if(i == complete){
            q.pop();
            complete = -1;
        }
        if(i == k * idx){
            q.push(order[idx]);
            idx++;
        }
        if(complete == -1 && !q.empty()){
            complete = i + menu[q.front()];
        }
        answer = max<int>(answer, q.size());
    }
    return answer;
}