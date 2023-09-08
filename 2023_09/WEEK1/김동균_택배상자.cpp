#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    stack<int> s;

    for(int i=0;i<order.size();i++){
      s.push(i+1);
       while(!s.empty() && s.top() == order[answer]){
            s.pop();
            answer++;
        }
    }
    
    return answer;
}