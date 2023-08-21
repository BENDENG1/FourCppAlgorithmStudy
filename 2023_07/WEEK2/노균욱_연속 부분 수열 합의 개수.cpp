/*
연속 부분 수열 합의 개수

자연수로 이루어진 원형
연속부분 수열의 합으로 만들 수 있는 수의 개수

원소의 갯수가 10개라면 뒤에 9개를 push_back을 한다.
-> ex) 8개 비교시 그냥 밀면서 끝까지 비교

1 2 3 4 5 -> 1 2 3 4 5 1 2 3 4로 함으로써
뒤에 push_back을 하면 편하긴 하지만 연산으로 i + j >= elements.size()라면 i +j - elements.size()로 진행

배열로 처음에 진행하였지만 1000 * 1000으로 인한 초과가 되기 때문에 앞으로 map을 애용해야겠다.
map<key,value>로 합을 key로 사용하기 때문에 value를 bool로 설정
*/

#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    
    map<int,bool>m;

    
    for(int i =0; i <elements.size();i++){
        int sum = 0;
        for(int j = 0; j<elements.size();j++){
            if(i + j >= elements.size()){
                sum += elements[i+ j - elements.size()];
            }else{
                sum += elements[i + j];
            }
            if(m.find(sum) == m.end()){ //존재하지 않으면 map으로 추가 
                m.insert({sum,true});
                answer++;
            }
        }
    }
    
    return answer;
}