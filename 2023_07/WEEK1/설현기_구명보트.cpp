/* 무게를 정렬한 후 제일 무게가 높은 사람부터 추출하여 제일 가벼운사람이랑 합한 무게가 
limit보다 작아 한 배에 태울수 있으면 answer++과 idx++(다음 가벼운사람 지목해야하니까) */
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end()); 
    int idx = 0;
    while(idx < people.size()){ 
        int back = people.back(); 
        people.pop_back();
        if(people[idx] + back <= limit){
            answer++;
            idx++;
        }
        else{ // 아니면 그냥 제일 무거운사람만 배를 태운다
            answer++;
        }
    }
    return answer;
}