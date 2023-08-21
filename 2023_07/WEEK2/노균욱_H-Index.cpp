/*
H-index

발표한 n평중 h번이상 인용된 논문이 h편 이상이고 나머지 논문이 h번 이하 인용되었다면 h의 최댓값이 이 과학자의 h-index

문제의 예시 5편 발표 -> 3번이상 인용

일단 역순으로 sort(내림차순)
내림차순 된 인덱스와 값을 비교한다. i + 1 < v[i] -> i < v[i] 라면 그것이 바로 h-index

*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int a, int b){
    return a > b;
}

int solution(vector<int> citations) {
    int answer = 0;
    
    sort(citations.begin(),citations.end(), compare);
    
    for(int i =0; i < citations.size();i++){        
        //h번이상 인용된 논문이 h편 이상 / 나머지 h번 이하 인용되었다면 h의 최댓값
        if(i<citations[i]){
            answer++;
        }else
            break;
    }
    
    return answer;
}