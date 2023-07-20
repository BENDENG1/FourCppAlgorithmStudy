#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q;
    for(int i = 0; i < speeds.size(); i++){
        q.push(i);
    }
    while(!q.empty()){
        int cnt = 0;
        for(int i = 0; i < speeds.size(); i++){
            progresses[i] += speeds[i];
        }
        while(!q.empty() && progresses[q.front()] >= 100){
            cnt++;
            q.pop();
        }
        if(cnt != 0){
            answer.push_back(cnt);
        }
    }
    return answer;
}