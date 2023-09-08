#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    int idx = 0;
    stack<int> s;
    int box = 1;
    
   while(1) {
        if(order[answer] == box) { 
            box++;
            answer++;
        } else if(!s.empty() && order[answer] == s.top()) {
            s.pop();
            answer++;
        } else if(box + 1 <= order.size()) { 
            s.push(box);
            box++;
        } else { 
            break;
        }
        
    }
    return answer;
}