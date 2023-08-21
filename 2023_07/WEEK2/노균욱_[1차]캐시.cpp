/*
공백,숫자,특수문자 등이 없는 영문자 + 대소문자 구분x
도시 이름은 최대 20자로 이루어져있음

Least Recently Used -> 최근에 사용하지 않은 캐시를 교체하는 알고리즘
cache hit -> 존재 한다면 1
cache miss -> 존재하지 않는다면 5 -> 크기가 채워졌냐 안채워졌냐로 분류

문제의 예시 2번째를 보면서 이해를 해봐야 함. 
편의상 jeju -> j , pangyo -> p seoul -> s로 하게 되면 아래와 같은 결과가 추출된다.
 j -> 5
 p -> 10
 s -> 15
 p s j -> 16  -> 최근에 사용된것을 뒤로 밀어 버리고 push_back()
 s j p -> 17
 j p s -> 18
 p s j -> 10
 s j p -> 20
 j p s -> 21
 
 일단 새로운게 나오면 그 위치의 index를 지우고 맨 뒤에 추가를 해준다.
 
*/
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;



int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    
    vector<string> cacheCities;
    
    //캐시 크기가 0이라면 굳이 작동도 할 필요없이 5*cities.size() return함
    if(cacheSize == 0)
        return 5 * cities.size();
    
    for(int i = 0; i < cities.size();i++){
        string str = cities[i];
        transform(str.begin(),str.end(), str.begin(),::tolower); //소문자로 변환
        
        auto it = find(cacheCities.begin(),cacheCities.end(),str);
        
        //cacheCities에 없을때 
        if(it == cacheCities.end()){
            answer += 5; // 없다는 것은 결국 cachemiss이므로 5
            // cacheCities가 아직 cacheSize를 채우지 않았을때
            if(cacheCities.size() < cacheSize){
                cacheCities.push_back(str);
            }else{
                cacheCities.erase(cacheCities.begin());
                cacheCities.push_back(str);
            }
        }else{ //cacheCities에 있을때
            answer++;
            cacheCities.erase(it);
            cacheCities.push_back(str);
        }
    }
    
    return answer;
}