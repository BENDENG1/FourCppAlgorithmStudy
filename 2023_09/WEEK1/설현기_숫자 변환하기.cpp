#include <string>
#include <vector>
#include <queue>
#include <set>
using namespace std;

int solution(int x, int y, int n) {
    int answer = 0;
    queue<pair<int, int>> q;
    set<int> s;
    
    s.insert(x);    
    q.push({x, 0});
    
    
    while(!q.empty()){
        int num = q.front().first;
        int cnt = q.front().second;
        q.pop();
        
        if(num == y) return cnt;
        
        else if(num < y){
            if(s.insert(num + n).second)
                q.push({num + n, cnt + 1});
            if(s.insert(num * 2).second)
                q.push({num * 2, cnt + 1});
            if(s.insert(num * 3).second)
                q.push({num * 3, cnt + 1});
        }
    }
    return -1;
}