/*
공평하게 나눠 토핑
1 2 1 3 1 4 1 2 -> 나눴을때 결국 맛볼 수 있는 토핑의 가짓 수 공평하게 자르는 방법의 수

일단 한명이 다 차지한다고 생각하고 진행 그리고 하나씩 당기면서 갯수 카운팅
*/

#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    map<int,int> second; //뒷놈
    map<int,int> first; // 앞놈
    for(int i = 0; i < topping.size();i++){
        second[topping[i]] += 1; //우선 뒷놈에 다 넣어버림
    }
    for(int i = 0; i < topping.size();i++){ //한칸씩 앞놈으로 가면서 갯수가 같으면 answer++함
        if(second.find(topping[i]) != second.end()){
            second[topping[i]] -= 1;
            first[topping[i]] += 1;
            if(second[topping[i]] == 0){ // 0이라는것은 없는거지 뒷놈 map지움
                second.erase(topping[i]);
            }
        }
        if(first.size() == second.size())
            answer++;
    }
    return answer;
}



/*
롤케이크 자르기

각 조각에 동일한 가짓수의 토핑 -> 공평

음 맵을 통해서 갯수에 대해서 ++을 해주고 --를 해주고 갯수가 같아질때에 대해서 진행을 한다면?

*/
#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    map<int,int> first;
    map<int,int> second;
    
    for(int i = 0 ; i < topping.size(); i++){
        second[topping[i]] += 1;
    }
    
    for(int i = 0 ; i < topping.size();i++){
        second[topping[i]] -= 1;
        first[topping[i]] += 1;
        if(second[topping[i]] == 0){
            second.erase(topping[i]);
        }
        if(first.size() == second.size())
            answer++;
        else if(first.size() > second.size())
            break;
    }
    return answer;
}