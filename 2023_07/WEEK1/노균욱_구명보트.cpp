/*
한번에 최대 2명씩 밖에 탈 수없고 무게 제한이 있음

구명보트를 최대한 적게 모든 사람을 구출

우선 sort를 통해 내림차순으로 정렬을 진행

어차피 최대 2명이 탈 수 있는것이기 때문에 우리는 가장 높은사람과 가장 낮은 사람과의 비교를 통해
조합이 가능하다면 ++ 아니라면 한명씩 태우는 방식을 진행하면 된다고 생각.

*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    
    sort(people.begin(), people.end());
    int i = 0;
    while (i < people.size()){
        int biggest = people.back(); // 가장 몸무게가 큰 사람과 낮은 사람들의 조합
        people.pop_back();
        if(people[i] + biggest <= limit){
            answer++;
            i++;
        }
        else
            answer++;
    }
    return answer;
}