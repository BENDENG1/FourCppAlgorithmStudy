#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <cctype>
using namespace std;

int solution(int cacheSize, vector<string> cities)
{
    deque<string> cache; // 캐시를 구현하기 위한 deque 사용
    int time = 0;        // 총 실행 시간

    for (int i = 0; i < cities.size(); i++)
    {
        string city = cities[i];
        transform(city.begin(), city.end(), city.begin(), ::tolower); // 대소문자 구분 없이 처리하기 위해 소문자로 변환
        auto it = find(cache.begin(), cache.end(), city);

        if (it != cache.end())     //it이 find의 의미 
        {                          
            cache.erase(it);       
            cache.push_back(city); // 가장 최근에 사용된 것으로 갱신
            time += 1;             // 실행 시간 1 증가 (캐시에서 조회한 경우)
        }
        else
        {                          // 캐시에 해당 도시가 없는 경우
            cache.push_back(city); // 캐시에 추가
            time += 5;             // 실행 시간 5 증가 (캐시에 추가하는 경우)

            if (cache.size() > cacheSize)
            {
                cache.pop_front(); // 캐시 크기를 초과하면 가장 오래된 도시를 제거
            }
        }
    }

    return time;
}