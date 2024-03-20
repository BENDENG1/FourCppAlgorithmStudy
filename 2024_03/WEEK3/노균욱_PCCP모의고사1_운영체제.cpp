/*
운영체제

점수 낮 -> 우선 순위 높

점수, 호출된 시간, 실행 시간 / a,b중복 고려 x

실행중인 것은 우선순위 높아도 끝내고 실행됨 / 우선순위 같으면 먼저 호출된 프로그램 실행

answer[i]는 1~10 점수가 i인 프로그램들의 대기시간의 합

pq로 풀면 되지 않나?

*/
#include <string>
#include <vector>
#include <queue>

using namespace std;

struct Schedule{
    int rank;
    int start;
    int time;
};

struct CompareRank {
    bool operator()(const Schedule &a, const Schedule &b){
        if (a.rank == b.rank){
            return a.start > b.start;
        }else
            return a.rank > b.rank;
    }
};

struct CompareTime {
    bool operator()(const Schedule& a, const Schedule& b){
        if (a.start == b.start)
            return a.rank > b.rank;
        else
            return a.start > b.start;
    }
};

vector<long long> solution(vector<vector<int>> programs) {
    vector<long long> answer(11,0);
    priority_queue<Schedule, vector<Schedule>, CompareTime> timePQ;
    priority_queue<Schedule,  vector<Schedule>, CompareRank> rankPQ;
    long long curTime = 0;
    
    for(auto program : programs)
        timePQ.push({program[0],program[1],program[2]});
    
    
    //우선순위 높 먼저 단, 하고있는것은 끝까지
    //우선순위 같으면 먼저 호출 된 것 
    while(!timePQ.empty() || !rankPQ.empty()){
        Schedule s;
        //먼저 현재 시간보다 (더한것도 포함) 낮은것들이 있는지
        while(!timePQ.empty()){
            s = timePQ.top();
            if(s.start > curTime)
                break;
            rankPQ.push(s);
            timePQ.pop();
        }
        if(rankPQ.empty()){
            s = timePQ.top();
            curTime = s.start + s.time;
            timePQ.pop();
        }
        else{
            s = rankPQ.top();
            if (curTime > s.start){
                answer[s.rank] += curTime - s.start;
                curTime += s.time;
            }
            else{
                curTime += s.time;
            }
            rankPQ.pop();
        }
    }
    answer[0] = curTime;
    return answer;
}