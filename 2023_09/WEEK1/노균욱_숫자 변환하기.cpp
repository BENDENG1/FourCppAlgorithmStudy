/*
자연수 x -> y
x + n / x * 2 / x * 3 중에 하나

선택을 하면서 만약에 숫자에 도달하면 최소횟수 return 만들수x -> -1 return

bfs로 풀어볼까? 
*/
#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int solution(int x, int y, int n) {
    int answer = 0;
    queue<pair<int,int>> q; //숫지,횟수
    bool visited[1000001] = {false,};
    q.push({x,0});
    
    while(!q.empty()){
        int num = q.front().first;
        int cnt = q.front().second;
        q.pop();
        
        if(num == y){
            return cnt;
        }
        
        if(num + n <= y && !visited[num + n]){
            q.push({num + n,cnt + 1});
            visited[num + n] = true;
        }
        if(num *2 <= y&& !visited[num * 2]){
            q.push({num *2,cnt + 1});
            visited[num * 2] = true;
        }
        if(num * 3 <= y && !visited[num * 3]){
            q.push({num * 3,cnt+1});
            visited[num * 3] = true;
        }
    }
    return -1;
}

/*
음 그냥 세가지 경우에 대해서 횟수를 집어넣고 
*/
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int x, int y, int n) {
    int answer = -1;
    queue<pair<int,int>> q;
    
    q.push({x,0});
    while(!q.empty()){
        int num = q.front().first;
        int cnt = q.front().second;
        q.pop();
        
        if(num == y){
            answer = cnt;
            break;
        }
        if(num * 2 <= y)q.push({num*2,cnt+1});
        if(num * 3 <= y)q.push({num*3,cnt+1});
        if(num + n <= y)q.push({num +n, cnt+1});
    }
    return answer;
}